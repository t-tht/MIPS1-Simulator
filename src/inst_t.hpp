#ifndef inst_H
#define inst_H

enum itype {R, I, J};

struct instruction_t {
	//define a struct for instruction that includes the different components of an instruction input
	uint32_t input;
	itype type;
	uint32_t opcode;
	uint32_t source1;
	uint32_t source2;
	uint32_t dest;
	uint32_t shift;
	uint32_t funct;
	uint32_t imm;		//immediate constants are for I type insturctions only
	uint32_t mem;		// for J type instructions

	void debug();		//debug which prints all the above values

};

void instruction_t::debug(){
	//debugging function
	std::cout <<  "input: " << input << std::endl;
	std::cout << "type: " << type << std::endl;
	std::cout <<  "opcode: " << opcode << std::endl;
	std::cout <<  "source1: " << source1 << std::endl;
	std::cout <<  "source2: " << source2 << std::endl;
	std::cout <<  "dest: " << dest << std::endl;
	std::cout <<  "shift: " << shift << std::endl;
	std::cout <<  "funct: " << funct << std::endl;
	std::cout <<  "immediate: " << imm << std::endl;
	std::cout <<  "memory: " << mem << std::endl;
}


#endif