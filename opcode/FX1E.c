#include "../chip8.h"
#include "../opcode.h"


void opcode_FX1E(const uint8_t X)
{
    const uint8_t VX = g_chip8->reg[X];

    if (g_chip8->I == 0xFFF && VX >= 1) {
        g_chip8->reg[0xF] = 1;
    }

    g_chip8->I += VX;
}
