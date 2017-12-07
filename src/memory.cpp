#include"memory.hpp"

struct mem_t{
	uint8_t value;
	uint32_t address;
};


err mem_print(unsigned char ROM[],size_t bytes) {
	for(int i = 0; i < bytes; i++){
		printf (" 0x%02x", ROM[i]);
    putchar ('\n');
	}
	return success;
}

err mem_read(uint32_t index, uint8_t value) {
	return success;
}



err mem_write(uint32_t index, uint8_t value){
	return success;
}

err mem_clear(uint32_t index){
	return success;
	
}