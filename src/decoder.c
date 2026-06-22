#include "../include/decoder.h"


DecodedInstruction decode(const uint32_t instruction) {
    DecodedInstruction instr;
    instr.opcode = instruction & 0x7F;
    instr.rd = (instruction >> 7) & 0x1F;
    instr.rs1 = (instruction >> 15) & 0x1F;
    instr.rs2 = (instruction >> 20) & 0x1F;
    instr.funct3 = (instruction >> 12) & 0x7;
    instr.funct7 = (instruction >> 25) & 0x7F;
    instr.imm = INST_UNKNOWN;
    if(instr.opcode == 0x33)
    {
        if(instr.funct3 == 0 &&
           instr.funct7 == 0)
        {
            instr.type = INST_ADD;
        }
        else if(instr.funct3 == 0 &&
                instr.funct7 == 0x20)
        {
            instr.type = INST_SUB;
        }
    }
    if(instr.opcode == 0x13 &&
   instr.funct3 == 0)
    {
        instr.type = INST_ADDI;
    }
    return instr;
}