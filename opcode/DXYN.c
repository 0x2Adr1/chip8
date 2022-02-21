#include "../chip8.h"
#include "../opcode.h"


void opcode_DXYN(const uint8_t X, const uint8_t Y, const uint8_t N)
{
    uint8_t x = g_chip8->reg[X] % CHIP8_SCREEN_WIDTH;
    uint8_t y = g_chip8->reg[Y] % CHIP8_SCREEN_HEIGHT;
    const uint8_t tmp_x = x;

    g_chip8->reg[0xF] = 0;

    for (unsigned row = 0; row < N; row++) {
        const uint8_t sprite_byte = g_chip8->ram[g_chip8->I + row];

        if (y >= CHIP8_SCREEN_HEIGHT) {
            return;
        }

        x = tmp_x;

        for (unsigned i = 0; i < 8; i++) {
            if (x >= CHIP8_SCREEN_WIDTH) {
                break;
            }

            if ((sprite_byte >> (7 - i)) & 1) {
                if (g_chip8->display.screen[y][x]) {
                    g_chip8->display.screen[y][x] = false;
                    g_chip8->reg[0xF] = 1;
                } else {
                    g_chip8->display.screen[y][x] = true;
                }
            }

            x++;
        }

        y++;
    }
}
