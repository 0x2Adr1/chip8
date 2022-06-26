#include "../chip8.h"
#include "../opcode.h"

#include <assert.h>


void opcode_00EE(void)
{
    assert(g_chip8->sp > 0);

    g_chip8->pc = g_chip8->stack[--g_chip8->sp];

    g_chip8->branch_taken = true;
}
