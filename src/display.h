#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifdef CHIP8_SUPER_CHIP
    #define CHIP8_SCREEN_WIDTH (128)
    #define CHIP8_SCREEN_HEIGHT (64)
#else
    #define CHIP8_SCREEN_WIDTH (64)
    #define CHIP8_SCREEN_HEIGHT (32)
#endif

typedef struct {
    void (*poll_events)(void);
    void (*display)(void);
    bool (*is_key_pressed)(const uint8_t key);

    bool screen[CHIP8_SCREEN_HEIGHT][CHIP8_SCREEN_WIDTH];
} display_t;

void display_init(void);
void display_cleanup(void);
