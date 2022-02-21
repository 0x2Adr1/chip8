#include "../opcode.h"

/*
 * pause execution of the CHIP-8 program and call a subroutine written in
 * machine language at address NNN instead.
 *
 * This routine would be written in the machine language of the computer’s CPU;
 * on the original COSMAC VIP and the ETI-660, this was 1802 machine code, and
 * on the DREAM 6800, M6800 code. Unless you’re making an emulator for either of
 * those computers, skip this one.
 */
void opcode_0NNN(const uint16_t NNN)
{
}
