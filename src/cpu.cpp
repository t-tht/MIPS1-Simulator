#include<iostream>
#include"inst_decode.cpp"
#include"inst_exe.cpp"

//create a cpu with inital conditions
void cpu_init(cpu_state_t& current_state){
	current_state.pc = 0;
	current_state.npc = 4;
	current_state.lo = 0;
	current_state.hi = 0;
	for(int i= 0; i < 32; i++){	//initalise register array to 0;
		current_state.reg[i] = 0;
	}
}

//sets pc counter
err cpu_set_pc(cpu_state_t& current_state, uint32_t pc){
	current_state.pc = pc;
	current_state.npc = current_state.pc + 4;
	return success;
}


//writes a register to a value
err cpu_write_reg(cpu_state_t& current_state, uint32_t register_no, uint32_t value){
	if(register_no == 0 || register_no > 31){ //check if its writing to register zero or >32
		std::cout << "register no available" << std::endl;
	}
	else{
		current_state.reg[register_no] = value;
		return success;
	}
}



//cpu runs 1 line of instruction
err cpu_run(cpu_state_t& current_state){ // need to add pointer to memory
	
	instruction_t current_inst;
	err error = success;
	
	//get instruction
	//temp input
	std::cout << "enter instruction:\t";
	std:cin >> std::hex >> current_inst.input;
	
	//decode
	
	if(error == success){
		std::cout << "decoding..............................................." << std::endl;
		error = inst_decode(current_inst); //might have to add state?
	}
	//execute
	if(error == success){
		std::cout << "executing..................................................." << std::endl;
		error = inst_exe(current_state, current_inst); //might have to add state?
		current_inst.debug();
		current_state.debug();
		
	}
	//pc increment
	if(error == success){
		std::cout << "incrementing pc..........................................." << std::endl;
		error = cpu_set_pc(current_state, current_state.pc + 4);
	}
	
	return error;
}

