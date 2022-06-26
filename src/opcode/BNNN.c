#include "../chip8.h"
#include "../opcode.h"


void opcode_BNNN(const uint16_t NNN)
{
#if QUIRK_BNNN_SUPER_CHIP
    g_chip8->pc = g_chip8->reg[NNN >> 8] + (NNN & 0xFF);
#else
    g_chip8->pc = NNN + g_chip8->reg[0];
#endif

    g_chip8->branch_taken = true;
}
