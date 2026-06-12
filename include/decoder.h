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
} DecodedInstruction;
#endif //RISC_V_EMULATOR_DECODER_H
