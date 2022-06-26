#include "../chip8.h"
#include "../opcode.h"


void opcode_8XY4(const uint8_t X, const uint8_t Y)
{
    if ((unsigned)g_chip8->reg[X] + (unsigned)g_chip8->reg[Y] > 255) {
        g_chip8->reg[0xF] = 1;
    } else {
        g_chip8->reg[0xF] = 0;
    }

    g_chip8->reg[X] += g_chip8->reg[Y];
}
