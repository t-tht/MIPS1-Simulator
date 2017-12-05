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
	cout <<  "input: " << input << endl;
	cout << "type: " << type << endl;
	cout <<  "opcode: " << opcode << endl;
	cout <<  "source1: " << source1 << endl;
	cout <<  "source2: " << source2 << endl;
	cout <<  "dest: " << dest << endl;
	cout <<  "shift: " << shift << endl;
	cout <<  "funct: " << funct << endl;
	cout <<  "immediate: " << imm << endl;
	cout <<  "memory: " << mem << endl;
}


#endif