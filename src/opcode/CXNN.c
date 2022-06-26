#include "../chip8.h"
#include "../opcode.h"

#include <stdlib.h>


void opcode_CXNN(const uint8_t X, const uint8_t NN)
{
    g_chip8->reg[X] = (rand() % 256) & NN;
}
