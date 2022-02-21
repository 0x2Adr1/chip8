#include "../chip8.h"
#include "../opcode.h"


void opcode_FX07(const uint8_t X)
{
    g_chip8->reg[X] = g_chip8->delay_timer;
}
