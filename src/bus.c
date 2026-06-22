#include "../include/bus.h"
#include "../include/memory.h"
void init_bus(Bus* bus, Memory* memory) {
    bus->memory = memory;
}
void bus_write(const Bus *bus, const uint32_t address, const uint8_t value){
    mem_write(bus->memory, address, value);
}
uint8_t bus_read(const Bus *bus, const uint32_t address) {
    return mem_read(bus->memory, address);
}
