#include "../chip8.h"
#include "../opcode.h"


void opcode_8XY5(const uint8_t X, const uint8_t Y)
{
    const uint8_t VX = g_chip8->reg[X];
    const uint8_t VY = g_chip8->reg[Y];

    g_chip8->reg[0xF] = (VX > VY) ? 1 : 0;
    g_chip8->reg[X] -= VY;
}
