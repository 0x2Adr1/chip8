#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "display.h"

typedef struct {
    // 4 KiB
    uint8_t* ram;

    // Program counter
    uint16_t pc;

    // Index register
    uint16_t I;

    uint8_t delay_timer;

    uint8_t sound_timer;

    // Registers
    uint8_t reg[16];

    bool branch_taken;

    display_t display;

    uint16_t stack[32];

    // Stack pointer
    unsigned sp;
} chip8_t;

void decode_execute(const uint16_t instruction);

extern chip8_t* g_chip8;
