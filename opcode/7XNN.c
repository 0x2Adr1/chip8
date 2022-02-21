#include "../chip8.h"
#include "../opcode.h"


void opcode_7XNN(const uint8_t X, const uint8_t NN)
{
    g_chip8->reg[X] += NN;
}
