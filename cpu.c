#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t IALIGN = 32;
uint32_t reg[32] = {0};
uint32_t pc = 0x00000;

#define RAM_SIZE (1024 * 1024)
uint8_t memory[RAM_SIZE];

/*
   There is no dedicated stack pointer or subroutine return address link
   register in the Base Integer ISA; the instruction encoding allows any x
   register to be used for these purposes. However, the standard software
   calling convention uses register x1 to hold the return address for a call,
   with register x5 available as an alternate link register.
   The standard calling convention uses register x2 as the stack pointer.
 */
enum {
  x0 = 0,
  x1, // return address register
  x2, // stack pointer
  x3,
  x4,
  x5,
  x6,
  x7,
  x8,
  x9,
  x10,
  x11,
  x12,
  x13,
  x14,
  x15,
  x16,
  x17,
  x18,
  x19,
  x20,
  x21,
  x22,
  x23,
  x24,
  x25,
  x26,
  x27,
  x28,
  x29,
  x30,
  x31
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Correct format: risc-v");
    exit(2);
  }
}
