#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "opcode.h"

// https://github.com/mattmikolay/chip-8/wiki/CHIP%E2%80%908-Instruction-Set
void decode_execute(const uint16_t instruction)
{
    const uint8_t most_significant_4_bits = (instruction >> 12);

    // Least significant 12 bits
    const uint16_t NNN = (instruction & 0xFFF);

    // Least significant 8 bits
    const uint8_t NN = (instruction & 0xFF);

    // Least significant 4 bits
    const uint8_t N = (instruction & 0xF);

    const uint16_t X = (instruction >> 8) & 0xF;
    const uint16_t Y = (instruction >> 4) & 0xF;

    char debug_str[64] = {0};

    switch (most_significant_4_bits) {
    case 0:
        switch (NNN) {
            case 0x0E0:
                sprintf(debug_str, "00E0");
                opcode_00E0();
                break;
            case 0x0EE:
                sprintf(debug_str, "00EE");
                opcode_00EE();
                break;
            default:
                sprintf(debug_str, "0NNN (NNN=%#x)", NNN);
                opcode_0NNN(NNN);
                break;
        }
        break;

    case 1:
        sprintf(debug_str, "1NNN (NNN=%#x)", NNN);
        opcode_1NNN(NNN);
        break;

    case 2:
        sprintf(debug_str, "2NNN (NNN=%#x)", NNN);
        opcode_2NNN(NNN);
        break;

    case 3:
        sprintf(debug_str, "3XNN (X=%#x, NN=%#x)", X, NN);
        opcode_3XNN(X, NN);
        break;

    case 4:
        sprintf(debug_str, "4XNN (X=%#x, NN=%#x)", X, NN);
        opcode_4XNN(X, NN);
        break;

    case 5:
        sprintf(debug_str, "5XY0 (X=%#x, Y=%#x)", X, Y);
        opcode_5XY0(X, NN);
        break;

    case 6:
        sprintf(debug_str, "6XNN (X=%#x, NN=%#x)", X, NN);
        opcode_6XNN(X, NN);
        break;

    case 7:
        sprintf(debug_str, "7XNN (X=%#x, NN=%#x)", X, NN);
        opcode_7XNN(X, NN);
        break;

    case 8:
        switch (N) {
        case 0:
            sprintf(debug_str, "8XY0 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY0(X, Y);
            break;
        case 1:
            sprintf(debug_str, "8XY1 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY1(X, Y);
            break;
        case 2:
            sprintf(debug_str, "8XY2 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY2(X, Y);
            break;
        case 3:
            sprintf(debug_str, "8XY3 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY3(X, Y);
            break;
        case 4:
            sprintf(debug_str, "8XY4 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY4(X, Y);
            break;
        case 5:
            sprintf(debug_str, "8XY5 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY5(X, Y);
            break;
        case 6:
            sprintf(debug_str, "8XY6 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY6(X, Y);
            break;
        case 7:
            sprintf(debug_str, "8XY7 (X=%#x, Y=%#x)", X, Y);
            opcode_8XY7(X, Y);
            break;
        case 0xE:
            sprintf(debug_str, "8XYE (X=%#x, Y=%#x)", X, Y);
            opcode_8XYE(X, Y);
            break;
        default:
            assert(false);
            break;
        }
        break;

    case 9:
        sprintf(debug_str, "9XY0 (X=%#x, Y=%#x)", X, Y);
        opcode_9XY0(X, Y);
        break;

    case 0xA:
        sprintf(debug_str, "ANNN (NNN=%#x)", NNN);
        opcode_ANNN(NNN);
        break;

    case 0xB:
        sprintf(debug_str, "BNNN (NNN=%#x)", NNN);
        opcode_BNNN(NNN);
        break;

    case 0xC:
        sprintf(debug_str, "CXNN (X=%#x, NN=%#x)", X, NN);
        opcode_CXNN(X, NN);
        break;

    case 0xD:
        sprintf(debug_str, "DXYN (X=%#x, Y=%#x, N=%#x)", X, Y, N);
        opcode_DXYN(X, Y, N);
        break;

    case 0xE:
        switch (NN) {
        case 0x9E:
            sprintf(debug_str, "EX9E (X=%#x)", X);
            opcode_EX9E(X);
            break;
        case 0xA1:
            sprintf(debug_str, "EXA1 (X=%#x)", X);
            opcode_EXA1(X);
            break;
        default:
            assert(false);
            break;
        }
        break;

    case 0xF:
        switch (NN) {
        case 0x7:
            sprintf(debug_str, "FX07 (X=%#x)", X);
            opcode_FX07(X);
            break;
        case 0xA:
            sprintf(debug_str, "FX0A (X=%#x)", X);
            opcode_FX0A(X);
            break;
        case 0x15:
            sprintf(debug_str, "FX15 (X=%#x)", X);
            opcode_FX15(X);
            break;
        case 0x18:
            sprintf(debug_str, "FX18 (X=%#x)", X);
            opcode_FX18(X);
            break;
        case 0x1E:
            sprintf(debug_str, "FX1E (X=%#x)", X);
            opcode_FX1E(X);
            break;
        case 0x29:
            sprintf(debug_str, "FX29 (X=%#x)", X);
            opcode_FX29(X);
            break;
        case 0x33:
            sprintf(debug_str, "FX33 (X=%#x)", X);
            opcode_FX33(X);
            break;
        case 0x55:
            sprintf(debug_str, "FX55 (X=%#x)", X);
            opcode_FX55(X);
            break;
        case 0x65:
            sprintf(debug_str, "FX65 (X=%#x)", X);
            opcode_FX65(X);
            break;
        default:
            assert(false);
            break;
        }
        break;
    }

#if 1
    puts(debug_str);
#endif
}
