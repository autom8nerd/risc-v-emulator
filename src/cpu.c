#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "ram.c"

uint32_t IALIGN = 32;
uint32_t reg[32] = {0};
uint32_t pc = 0x00000;

uint8_t memory[RAM_SIZE];

/*
   There is no dedicated stack pointer or subroutine return address link
   register in the Base Integer ISA; the instruction encoding allows any x
   register to be used for these purposes. However, the standard software
   calling convention uses register x1 to hold the return address for a call,
   with register x5 available as an alternate link register.
   The standard calling convention uses register x2 as the stack pointer.
 */

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Correct format: /.%s <binary file>", argv[0]);
    exit(2);
  }
  // open the binary file passed
  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  size_t prog_size = fread(memory, 1, RAM_SIZE, file);
  fclose(file);

  uint32_t instr = memory[pc] | (memory[pc + 1] << 8) | (memory[pc + 2] << 16) |
                   (memory[pc + 3] << 24);

  uint32_t opcode = instr & 0x7F;

  switch (opcode) {
  case 0x13: { // ADD instruction
    uint32_t rd = (instr >> 7) & 0x1F;
    uint32_t rs1 = (instr >> 15) & 0x1F;
    uint32_t funct3 = (instr >> 12) & 0x07;

    int32_t imm_value = (int32_t)instr >> 20;

    if (funct3 == 0x0) {
      reg[rd] = reg[rs1] + imm_value;
    } else if (funct3 == 0x2) {
      if ((int32_t)reg[rs1] < (int32_t)imm_value) {
        reg[rd] = 1;
      } else {
        reg[rd] = 0;
      }
    }

    pc += 4;
    break;
  }
  }
}
