#ifndef inst_H
#define inst_H

struct instruction_t {
	//define a struct for instruction that includes the different components of an instruction input
	uint32_t input;
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

enum itype {R, I, J};


#endif