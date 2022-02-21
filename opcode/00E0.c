#include "../chip8.h"
#include "../opcode.h"

#include <string.h>


// Clear screen
void opcode_00E0(void)
{
    memset(g_chip8->display.screen, 0, sizeof(g_chip8->display.screen));
}
