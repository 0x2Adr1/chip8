#include "../chip8.h"
#include "../opcode.h"


void opcode_8XY7(const uint8_t X, const uint8_t Y)
{
    const uint8_t VX = g_chip8->reg[X];
    const uint8_t VY = g_chip8->reg[Y];

    g_chip8->reg[0xF] = (VY > VX) ? 1 : 0;
    g_chip8->reg[X] = VY - VX;
}
