//
// Created by fsoc on 12/06/26.
//

#ifndef RISC_V_EMULATOR_DECODER_H
#define RISC_V_EMULATOR_DECODER_H
#include <stdint.h>
typedef struct DecodedInstruction{
    uint8_t opcode;
    uint8_t rd;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct3;
    uint8_t funct7;
    uint8_t imm;
    uint8_t type;
} DecodedInstruction;
DecodedInstruction decode(uint32_t);
typedef enum {
    INST_ADD,
    INST_SUB,
    INST_ADDI,
    INST_LW,
    INST_SW,
    INST_BEQ,
    INST_BNE,
    INST_JAL,
    INST_JALR,
    INST_LUI,
    INST_AUIPC,
    INST_UNKNOWN
} InstructionType;
#endif //RISC_V_EMULATOR_DECODER_H
