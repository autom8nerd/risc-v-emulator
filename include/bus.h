//
// Created by fsoc on 12/06/26.
//

#ifndef RISC_V_EMULATOR_BUS_H
#define RISC_V_EMULATOR_BUS_H
#include "../include/memory.h"
typedef struct {
    Memory* memory;
} Bus;

void init_bus(Bus* bus, Memory* memory);
void bus_write(const Bus *bus, uint32_t address, uint8_t value);
uint8_t bus_read(const Bus *bus, uint32_t address);
#endif //RISC_V_EMULATOR_BUS_H
