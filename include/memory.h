//
// Created by fsoc on 12/06/26.
//

#ifndef RISC_V_EMULATOR_MEMORY_H
#define RISC_V_EMULATOR_MEMORY_H
#define MEMORY_SIZE (1024 * 1024)
#include <stdint.h>
typedef struct {
    uint8_t mem[MEMORY_SIZE];
} Memory;
void init_memory(Memory* memory);
uint8_t mem_read(const Memory* memory, uint32_t address);
void mem_write(Memory* memory, uint32_t address, uint8_t value);
#endif //RISC_V_EMULATOR_MEMORY_H
