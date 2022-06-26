#include "../chip8.h"
#include "../opcode.h"


void opcode_FX29(const uint8_t X)
{
    const uint8_t VX = g_chip8->reg[X];

    g_chip8->I = (VX & 0xF) * 5;
}
