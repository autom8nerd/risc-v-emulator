//
// Created by fsoc on 12/06/26.
//

#ifndef RISC_V_EMULATOR_CPU_H
#define RISC_V_EMULATOR_CPU_H
#include "../include/decoder.h"
#include <stdint.h>
#include "../include/bus.h"
typedef struct {
    uint32_t reg[1<<5];
    uint32_t pc;
    Bus* bus;
} CPU;
enum Register {
    x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20, x21, x22, x23, x24,
    x25, x26, x27, x28, x29, x30, x31
};

/*x1 holds the return instruction address, x2 is used as stack pointer and x5 as an alternative*/
void init_cpu(CPU* cpu, Bus* bus);
uint32_t cpu_fetch32(const CPU* cpu);
void execute(CPU* cpu, const DecodedInstruction* instr);
#endif //RISC_V_EMULATOR_CPU_H
