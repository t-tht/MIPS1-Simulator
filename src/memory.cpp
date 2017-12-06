#include"memory.hpp"

struct mem_t{
	uint8_t value;
	uint32_t address;
};


err mem_init(uint8_t* memptr) {
	for(int i = 0; i < 100; i++){
		(memptr)[i];
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