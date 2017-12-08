#include"memory.hpp"
#include <stdint.h>
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

uint32_t mem_instruction(unsigned char ROM[], uint32_t pc) {
	return	(ROM[pc]<<24)|(ROM[pc+1]<<16)|(ROM[pc+2]<<8)|(ROM[pc+3]);
	
}

err mem_read(unsigned char ROM[], uint32_t index, uint8_t& value){
	value=ROM[index];
	return success;
}

err mem_write(unsigned char ROM[], uint32_t index, uint8_t value){
	ROM[index]=value;
	return success;
}

err mem_clear(unsigned char ROM[], uint32_t index){
	ROM[index]=0;
	return success;
	
}