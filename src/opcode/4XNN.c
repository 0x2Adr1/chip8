#include "../chip8.h"
#include "../opcode.h"


void opcode_4XNN(const uint8_t X, const uint8_t NN)
{
    if (g_chip8->reg[X] != NN) {
        g_chip8->pc += 2;
    }
}
