#include "../include/memory.h"
#include "../include/bus.h"
#include "../include/cpu.h"
#include "../include/decoder.h"
#include <stdio.h>
Memory memory;
Bus bus;
CPU cpu;
int main(){
    init_cpu(&cpu, &bus);

    cpu.reg[x10] = 5;
    cpu.reg[x11] = 7;

    DecodedInstruction instr;

    instr.type = INST_ADD;
    instr.rd   = x12;
    instr.rs1  = x10;
    instr.rs2  = x11;

    execute(&cpu, &instr);

    printf("x12 = %u\n", cpu.reg[x12]);
    printf("pc  = %u\n", cpu.pc);
    mem_write32(&memory, 0, 0x12345678);

    printf("%02X\n", memory.mem[0]);
    printf("%02X\n", memory.mem[1]);
    printf("%02X\n", memory.mem[2]);
    printf("%02X\n", memory.mem[3]);

    printf("%08X\n", mem_read32(&memory, 0));
}