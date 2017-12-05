#include"memory.hpp"
#define MEMSIZE 4294967296

uint8_t mem[MEMSIZE];

struct mem_t{
	uint8_t value;
	uint32_t address;
};

err mem_read(index, content, memorypointer) {
	
}



err mem_write(index, content, state) {
	state.mem
}

err mem_clear(index) {
	
}