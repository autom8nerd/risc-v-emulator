#include "../include/cpu.h"
void init_cpu(CPU *cpu) { //initialized the CPU that is defined inside cpu.h
    cpu->pc = 0x00000;
    for (int i = 0;i<32;i++) {
        cpu->reg[i] = 0x00000;
    }
}
