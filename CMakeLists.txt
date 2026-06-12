cmake_minimum_required(VERSION 4.0)

project (risc-v-emulator)

set(CMAKE_C_STANDARD 20)
add_executable(src/cpu.c
        src/memory.c
        src/main.c
        src/bus.c
        src/decoder.c
)