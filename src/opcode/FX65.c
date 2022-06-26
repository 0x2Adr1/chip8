#include "../chip8.h"
#include "../opcode.h"


void opcode_FX65(const uint8_t X)
{
    for (int i = 0; i <= X; i++) {
        g_chip8->reg[X + i] = g_chip8->ram[g_chip8->I + i];
    }

#if QUIRK_FX55_FX65_ORIGINAL
    g_chip8->I += X + 1;
#endif
}
