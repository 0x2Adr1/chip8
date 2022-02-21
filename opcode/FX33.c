#include "../chip8.h"
#include "../opcode.h"


void opcode_FX33(const uint8_t X)
{
    uint8_t VX = g_chip8->reg[X];

    for (int i = 0; i < 3; i++) {
        const uint8_t digit = VX % 10;
        VX /= 10;

        g_chip8->ram[g_chip8->I + (2 - i)] = digit;
    }
}
