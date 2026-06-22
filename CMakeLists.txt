cmake_minimum_required(VERSION 4.0)

project(risc-v-emulator C)

set(CMAKE_C_STANDARD 23)

add_executable(
        riscv_emulator
        src/main.c
        src/cpu.c
        src/memory.c
        src/bus.c
        src/decoder.c
)