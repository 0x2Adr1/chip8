#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include "chip8.h"
#include "opcode.h"

#define ROM_MAX_SIZE (4 * 1024 - 0x200)

// 60Hz
#define TIMER_DELAY_MS (1000 / 60)

chip8_t* g_chip8 = NULL;

static uint8_t g_fonts[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80, // F
};

static void
chip8_destroy(chip8_t* chip8)
{
    if (chip8 == NULL) {
        return;
    }

    free(chip8->ram);
    chip8->ram = NULL;

    free(chip8);
}

static chip8_t*
chip8_create(const char* filename)
{
    chip8_t* chip8 = calloc(1, sizeof(chip8_t));

    // 4 KiB of RAM
    chip8->ram = calloc(4 * 1024, sizeof(uint8_t));

    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        perror("fopen");
        goto err;
    }

    fseek(f, 0, SEEK_END);
    const size_t file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (file_size > ROM_MAX_SIZE) {
        fprintf(stderr, "ROM is too big (%zu bytes)\n", file_size);
        goto err;
    }

    if (fread(&chip8->ram[0x200], 1, file_size, f) != file_size) {
        goto err;
    }

    // Copy font data to the interpreter reserved memory region
    memcpy(&chip8->ram[0], g_fonts, sizeof(g_fonts));

    chip8->pc = 0x200;
    chip8->sp = 0;

    return chip8;

err:
    chip8_destroy(chip8);
    return NULL;
}

static uint64_t
get_ticks(void)
{
    struct timeval now;
    static struct timeval start;
    static bool initialized = false;

    if (!initialized) {
        if (gettimeofday(&start, NULL) != 0) {
            perror("gettimeofday");
            exit(EXIT_FAILURE);
        }

        initialized = true;
    }

    if (gettimeofday(&now, NULL) != 0) {
        perror("gettimeofday");
        exit(EXIT_FAILURE);
    }

    return (uint64_t)(((int64_t)(now.tv_sec - start.tv_sec) * 1000) + ((now.tv_usec - start.tv_usec) / 1000));
}

int
main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage: %s <rom>\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    const char* filename = argv[1];

    g_chip8 = chip8_create(filename);

    if (g_chip8 == NULL) {
        return EXIT_FAILURE;
    }

    display_init();

    uint64_t timer_timeout = get_ticks() + TIMER_DELAY_MS;

    for (;;) {
        if (get_ticks() > timer_timeout) {
            if (g_chip8->delay_timer > 0) {
                g_chip8->delay_timer--;
            }

            timer_timeout = get_ticks() + TIMER_DELAY_MS;
        }

        const uint16_t instruction =
            (g_chip8->ram[g_chip8->pc] << 8) + g_chip8->ram[g_chip8->pc + 1];

        // Must be set before the call to decode_execute()
        g_chip8->branch_taken = false;

        //printf("%.4hx\n", instruction);

        g_chip8->display.poll_events();
        g_chip8->display.display();

        decode_execute(instruction);

        if (!g_chip8->branch_taken) {
            g_chip8->pc += 2;
        }
    }

    display_cleanup();

    chip8_destroy(g_chip8);
    g_chip8 = NULL;

    return EXIT_SUCCESS;
}
