#include "../chip8.h"
#include "../opcode.h"


void opcode_5XY0(const uint8_t X, const uint8_t Y)
{
    if (g_chip8->reg[X] == g_chip8->reg[Y]) {
        g_chip8->pc += 2;
    }
}
