#include "../include/cpu.h"
#include "../include/decoder.h"
#include <stdio.h>
#include <stdlib.h>

void init_cpu(CPU *cpu, Bus* bus) { //initialized the CPU that is defined inside cpu.h
    cpu->pc = 0;
    cpu->bus = bus;
    for (int i = 0;i<32;i++) {
        cpu->reg[i] = 0;
    }
}

void execute(CPU* cpu, const DecodedInstruction* instr) {
    switch (instr->type) {
        case INST_ADD:
            cpu->reg[instr->rd] = cpu->reg[instr->rs1] + cpu->reg[instr->rs2];
            break;
        case INST_SUB:
            cpu->reg[instr->rd] = cpu->reg[instr->rs1] - cpu->reg[instr->rs2];
            break;
        case INST_ADDI:
            cpu->reg[instr->rd] = cpu->reg[instr->rs1] + instr->imm;
            break;
        case INST_LW:
            cpu->reg[instr->rd] = bus_read32(cpu->bus, cpu->reg[instr->rs1] + instr->imm);
            break;
        case INST_SW:
            bus_write32(cpu->bus, cpu->reg[instr->rs1 + instr->imm], cpu->reg[instr->rs2]);
        default:
            printf("Unknown instruction\n");
            exit(EXIT_FAILURE);
    }
    cpu->pc+=4;
    cpu->reg[x0] = 0;
}

uint32_t cpu_fetch32(const CPU* cpu) {
    return bus_read32(cpu->bus, cpu->pc);
}