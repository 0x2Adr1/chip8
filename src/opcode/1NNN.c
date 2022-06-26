#include "../opcode.h"

#include "../chip8.h"


void opcode_1NNN(const uint16_t NNN)
{
    g_chip8->pc = NNN;
    g_chip8->branch_taken = true;
}
