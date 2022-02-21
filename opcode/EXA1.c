#include "../chip8.h"
#include "../opcode.h"


void opcode_EXA1(const uint8_t X)
{
    const uint8_t VX = g_chip8->reg[X];

    if (!g_chip8->display.is_key_pressed(VX)) {
        g_chip8->pc += 2;
    }
}
