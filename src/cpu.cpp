#include<iostream>
#include"cpu.hpp"

//create a cpu with inital conditions
void cpu_start(){
	currentcpu.pc = 0;
	currentcpu.npc = 4;
	for(int i= 0; i < 32; i++){	//initalise register array to 0;
		currentcpu.reg[i] = 0;
	}
}

//writes a register to a value
void cpu_write_reg(uint32_t register_no, uint32_t value){
	if(register_no == 0 || register_no > 31){ //check if its writing to register zero or >32
		mips_error = error_inv_handle;
	}
	else{
		currentcpu.reg[register_no] = value;
	}
}


void cpu_exit(){
	std::cout << "Exit Failure" << std::endl;
	exit(EXIT_FAILURE);
}
