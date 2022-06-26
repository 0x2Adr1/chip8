#include "../chip8.h"
#include "../opcode.h"


void opcode_2NNN(const uint16_t NNN)
{
    g_chip8->stack[g_chip8->sp++] = g_chip8->pc + 2;

    g_chip8->pc = NNN;

    g_chip8->branch_taken = true;
}
