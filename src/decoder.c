#include "../include/decoder.h"

DecodedInstruction  *instr;

void decode(const uint32_t instruction) {
    instr->opcode = instruction & 0x7F;
    instr->rd = (instruction >> 7) & 0x1F;
    instr->rs1 = (instruction>>15) & 0x1F;
    instr->rs2 = (instruction >> 20) & 0x1F;
    instr->funct3 = (instruction>>12) & 0x7;
}