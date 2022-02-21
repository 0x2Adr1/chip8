#pragma once

#include <stdint.h>

void opcode_00E0(void);
void opcode_00EE(void);

void opcode_0NNN(const uint16_t NNN);

void opcode_1NNN(const uint16_t NNN);

void opcode_2NNN(const uint16_t NNN);

void opcode_3XNN(const uint8_t X, const uint8_t NN);

void opcode_4XNN(const uint8_t X, const uint8_t NN);

void opcode_5XY0(const uint8_t X, const uint8_t Y);

void opcode_6XNN(const uint8_t X, const uint8_t NN);

void opcode_7XNN(const uint8_t X, const uint8_t NN);

void opcode_8XY0(const uint8_t X, const uint8_t Y);
void opcode_8XY1(const uint8_t X, const uint8_t Y);
void opcode_8XY2(const uint8_t X, const uint8_t Y);
void opcode_8XY3(const uint8_t X, const uint8_t Y);
void opcode_8XY4(const uint8_t X, const uint8_t Y);
void opcode_8XY5(const uint8_t X, const uint8_t Y);
void opcode_8XY6(const uint8_t X, const uint8_t Y);
void opcode_8XY7(const uint8_t X, const uint8_t Y);
void opcode_8XYE(const uint8_t X, const uint8_t Y);

void opcode_9XY0(const uint8_t X, const uint8_t Y);

void opcode_ANNN(const uint16_t NNN);

void opcode_BNNN(const uint16_t NNN);

void opcode_CXNN(const uint8_t X, const uint8_t NN);

void opcode_DXYN(const uint8_t X, const uint8_t Y, const uint8_t N);

void opcode_EX9E(const uint8_t X);
void opcode_EXA1(const uint8_t X);

void opcode_FX07(const uint8_t X);
void opcode_FX0A(const uint8_t X);
void opcode_FX15(const uint8_t X);
void opcode_FX18(const uint8_t X);
void opcode_FX1E(const uint8_t X);
void opcode_FX29(const uint8_t X);
void opcode_FX33(const uint8_t X);
void opcode_FX55(const uint8_t X);
void opcode_FX65(const uint8_t X);
