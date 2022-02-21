#include "../chip8.h"
#include "../opcode.h"


void opcode_8XY2(const uint8_t X, const uint8_t Y)
{
    g_chip8->reg[X] &= g_chip8->reg[Y];
}
