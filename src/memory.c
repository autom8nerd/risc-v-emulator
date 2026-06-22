#include "../include/memory.h"

#include <stddef.h>

void init_memory(Memory* memory) {
    for (size_t i = 0; i < MEMORY_SIZE; i++) {
        memory->mem[i] = 0;
    }
}
void mem_write(Memory* memory, const uint32_t address, uint8_t value) {
    memory->mem[address] = value;
}

uint8_t mem_read(const Memory* memory, uint32_t address) {
    return memory->mem[address];
}
