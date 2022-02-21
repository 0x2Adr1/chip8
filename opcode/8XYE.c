#include "../chip8.h"
#include "../opcode.h"


void opcode_8XYE(const uint8_t X, const uint8_t Y)
{
    uint8_t* VX = &g_chip8->reg[X];
    const uint8_t* VY = &g_chip8->reg[Y];

#if QUIRK_8XY6_8XYE_SUPER_CHIP
    *VX = *VY;
#endif

    const uint8_t shifted_bit = (*VX) >> 7;

    *VX <<= 1;

    g_chip8->reg[0xF] = shifted_bit;
}
