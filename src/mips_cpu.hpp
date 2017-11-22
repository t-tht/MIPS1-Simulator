/*
	CONTAINS CPU FUNCTIONS
*/

#ifndef mips_cpu_H
#define mips_cpu_H

#include<iostream>
#include"mips_error.hpp"

using namespace std;

struct cpu_state{
	uint32_t pc;
	uint32_t npc;
	uint32_t reg[32];
};

cpu_state current;
error_type mips_error;

void cpu_start(){
	//create a cpu with inital conditions
	current.pc = 0;
	current.npc = 4;
	for(int i= 0; i < 32; i++){	//initalise register array to 0;
		current.reg[i] = 0;
	}
}

void cpu_write_reg(uint32_t register_no, uint32_t value){
	//writes a register to a value
	if(register_no == 0 || register_no > 31){
		mips_error = error_inv_handle;
	}
	else{
		current.reg[register_no] = value;
	}
}

void cpu_exit(){
	cout << "Exit Failure" << endl;
	exit(EXIT_FAILURE);
}

#endif
