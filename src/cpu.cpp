/*
contains cpu functions
*/

/*
TO DO LIST:
---------------------------------------
1.
*/
#include<iostream>
#include"cpu.hpp"
#include"error.hpp"
#include"inst_decode.cpp"
#include"inst_exe.cpp"

//create a cpu with inital conditions
void cpu_start(){
	current_state.pc = 0;
	current_state.npc = 4;
	current_state.lo = 0;
	current_state.hi = 0;
	current_state.error = 0;
	for(int i= 0; i < 32; i++){	//initalise register array to 0;
		current_state.reg[i] = 0;
	}
}

//increments pc counter
err cpu_set_pc(cpu_state_t& current_state, uint32_t pc){
		current_state.pc = pc;
		current_state.npc = current_state.pc + 4;
	return success;
}


//writes a register to a value
err cpu_write_reg(uint32_t register_no, uint32_t value){
	if(register_no == 0 || register_no > 31){ //check if its writing to register zero or >32
		return err_handle;
	}
	else{
		current_state.reg[register_no] = value;
	}
}



//cpu runs 1 line of instruction
err cpu_run(cpu_state_t state){
	
	instruction_t current_inst;
	err error;
	
	//get instruction
	//decode
	if(error == success){
		error = inst_decode(current_instruction);
	}
	//execute
	if(error == success){
		error = inst_exe(current_instruction);
	}
	//pc increment
	if(error == success){
		error = cpu_set_pc(current_state, current_state.pc + 4);
	}
	
	return error;
}


void cpu_exit(){
	std::cout << "Exit Failure" << std::endl;
	exit(EXIT_FAILURE);
}
