#include "../include/memory.h"
#include "../include/bus.h"
#include <stdio.h>
Memory memory;
Bus bus;
int main() {
    init_memory(&memory);
    init_bus(&bus, &memory);

    bus_write(&bus, 0x100, 42);

    printf("%u\n", bus_read(&bus, 0x100));
}