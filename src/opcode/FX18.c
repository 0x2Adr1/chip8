#include "../chip8.h"
#include "../opcode.h"


void opcode_FX18(const uint8_t X)
{
    g_chip8->sound_timer = g_chip8->reg[X];
}
