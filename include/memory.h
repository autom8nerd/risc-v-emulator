//
// Created by fsoc on 12/06/26.
//

#ifndef RISC_V_EMULATOR_MEMORY_H
#define RISC_V_EMULATOR_MEMORY_H

typedef struct {
    uint32_t mem[1<<32];
} MEMORY;
void init_memory(MEMORY* memory);
#endif //RISC_V_EMULATOR_MEMORY_H
