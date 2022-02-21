#include "../chip8.h"
#include "../opcode.h"


void opcode_FX0A(const uint8_t X)
{
    for (int key = 0; key <= 0xF; key++) {
        if (g_chip8->display.is_key_pressed(key)) {
            return;
        }
    }

    g_chip8->pc -= 2;
}
