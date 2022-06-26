#include "../chip8.h"
#include "../opcode.h"


void opcode_ANNN(const uint16_t NNN)
{
    g_chip8->I = NNN;
}
