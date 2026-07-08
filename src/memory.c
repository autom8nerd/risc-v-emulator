#include "../include/memory.h"

#include <stddef.h>

#include "../include/cpu.h"

void init_memory(Memory* memory) {
    for (size_t i = 0; i < MEMORY_SIZE; i++) {
        memory->mem[i] = 0;
    }
}
void mem_write(Memory* memory, const uint32_t address, uint8_t value) {
    memory->mem[address] = value;
}

uint8_t mem_read8(const Memory* memory, uint32_t address) {
    return memory->mem[address];
}
uint32_t mem_read32(const Memory* memory, uint32_t address){
    uint32_t result =
        (uint32_t)memory->mem[address] |
        ((uint32_t)memory->mem[address+1] << 8) |
        ((uint32_t)memory->mem[address+2] << 16) |
        ((uint32_t)memory->mem[address+3] << 24);
    return result;
}

void mem_write32(Memory* memory, const uint32_t address, const uint32_t value) {
    memory->mem[address] = (uint8_t)(value & 0xFF);
    memory->mem[address+1] = (uint8_t)((value>>8) & 0xFF);
    memory->mem[address+2] = (uint8_t)((value >> 16) & 0xFF);
    memory->mem[address+3] = (uint8_t)((value >> 24) & 0xFF);
}