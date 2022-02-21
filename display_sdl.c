#include "chip8.h"
#include "display.h"

#include <assert.h>

#include <SDL.h>

#define SCALE_FACTOR (10)
#define SCREEN_WIDTH (CHIP8_SCREEN_WIDTH * SCALE_FACTOR)
#define SCREEN_HEIGHT (CHIP8_SCREEN_HEIGHT * SCALE_FACTOR)

static SDL_Renderer *g_renderer;
static SDL_Window *g_window;

static SDL_Point* g_points;


static void
poll_events(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;

        default:
            break;
        }
    }
}

static void
display(void)
{
    unsigned count = 0;

    for (int x = 0; x < CHIP8_SCREEN_WIDTH; x++) {
        for (int y = 0; y < CHIP8_SCREEN_HEIGHT; y++) {
            if (!g_chip8->display.screen[y][x]) {
                continue;
            }

            for (int row = 0; row < SCALE_FACTOR; row++) {
                for (int col = 0; col < SCALE_FACTOR; col++) {
                    g_points[count].y = y * SCALE_FACTOR + row;
                    g_points[count].x = x * SCALE_FACTOR + col;
                    count++;
                }
            }
        }
    }

    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0);
    SDL_RenderClear(g_renderer);

    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
    int ret = SDL_RenderDrawPoints(g_renderer, g_points, count);

    if (ret != 0) {
        fprintf(stderr, "SDL_RenderDrawPoints: %s\n", SDL_GetError());
    }

    SDL_RenderPresent(g_renderer);
}

static bool
is_key_pressed(const uint8_t key)
{
    const uint8_t* state = SDL_GetKeyboardState(NULL);

    switch (key) {
    case 0:
        return state[SDL_SCANCODE_0] == 1;
    case 1:
        return state[SDL_SCANCODE_1] == 1;
    case 2:
        return state[SDL_SCANCODE_2] == 1;
    case 3:
        return state[SDL_SCANCODE_3] == 1;
    case 4:
        return state[SDL_SCANCODE_4] == 1;
    case 5:
        return state[SDL_SCANCODE_5] == 1;
    case 6:
        return state[SDL_SCANCODE_6] == 1;
    case 7:
        return state[SDL_SCANCODE_7] == 1;
    case 8:
        return state[SDL_SCANCODE_8] == 1;
    case 9:
        return state[SDL_SCANCODE_9] == 1;
    case 0xA:
        return state[SDL_SCANCODE_A] == 1;
    case 0xB:
        return state[SDL_SCANCODE_B] == 1;
    case 0xC:
        return state[SDL_SCANCODE_C] == 1;
    case 0xD:
        return state[SDL_SCANCODE_D] == 1;
    case 0xE:
        return state[SDL_SCANCODE_E] == 1;
    case 0xF:
        return state[SDL_SCANCODE_F] == 1;
    }

    assert(false);
    return false;
}

void
display_cleanup(void)
{
    free(g_points);
    g_points = NULL;
}

void
display_init(void)
{
    g_chip8->display.poll_events = poll_events;
    g_chip8->display.display = display;
    g_chip8->display.is_key_pressed = is_key_pressed;

    g_points = calloc(SCREEN_WIDTH * SCREEN_HEIGHT, sizeof(SDL_Point));

    assert(SCALE_FACTOR >= 1);

    const int rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    const int windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    g_window = SDL_CreateWindow("Chip-8", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (g_window == NULL) {
        printf("Failed to open %ux%u window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    g_renderer = SDL_CreateRenderer(g_window, -1, rendererFlags);

    if (g_renderer == NULL) {
            printf("Failed to create renderer: %s\n", SDL_GetError());
            exit(1);
    }
}
