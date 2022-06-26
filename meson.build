project('chip8',
        'c',
        default_options : [
            'c_std=c11',
        ]
)

# for f in $(find . -name "*.c" | sort); do echo "'$f',"; done
src_chip8 = files([
    './src/decode.c',
    './src/display_sdl.c',
    './src/main.c',

    './src/opcode/00E0.c',
    './src/opcode/00EE.c',
    './src/opcode/0NNN.c',
    './src/opcode/1NNN.c',
    './src/opcode/2NNN.c',
    './src/opcode/3XNN.c',
    './src/opcode/4XNN.c',
    './src/opcode/5XY0.c',
    './src/opcode/6XNN.c',
    './src/opcode/7XNN.c',
    './src/opcode/8XY0.c',
    './src/opcode/8XY1.c',
    './src/opcode/8XY2.c',
    './src/opcode/8XY3.c',
    './src/opcode/8XY4.c',
    './src/opcode/8XY5.c',
    './src/opcode/8XY6.c',
    './src/opcode/8XY7.c',
    './src/opcode/8XYE.c',
    './src/opcode/9XY0.c',
    './src/opcode/ANNN.c',
    './src/opcode/BNNN.c',
    './src/opcode/CXNN.c',
    './src/opcode/DXYN.c',
    './src/opcode/EX9E.c',
    './src/opcode/EXA1.c',
    './src/opcode/FX07.c',
    './src/opcode/FX0A.c',
    './src/opcode/FX15.c',
    './src/opcode/FX18.c',
    './src/opcode/FX1E.c',
    './src/opcode/FX29.c',
    './src/opcode/FX33.c',
    './src/opcode/FX55.c',
    './src/opcode/FX65.c',
])

executable(
    'chip8',
    src_chip8,
    dependencies: [
        dependency('sdl2'),
    ],
)
