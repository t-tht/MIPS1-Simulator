#ifndef mips_decode_H
#define mips_decode_H

using namespace std;

typedef struct instruction_t{
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

	void debug(){
		cout <<  "input: " << input << endl;
		cout <<  "opcode: " << opcode << endl;
		cout <<  "source1: " << source1 << endl;
		cout <<  "source2: " << source2 << endl;
		cout <<  "dest: " << dest << endl;
		cout <<  "shift: " << shift << endl;
		cout <<  "funct: " << funct << endl;
		cout <<  "immediate: " << imm << endl;
		cout <<  "memory: " << mem << endl;
	}

}instruction_t;

void r_decode(instruction_t& current){			
	/*decoding for r type instructions
	opcode[31-26], source1[25-21], source2[20-16], dest[15-11], shift[10-6], funct[5-0]
	*/
	cout << "r_decode" << endl << endl;
	current.source1 = (current.input >> 21) & 0x1F;
	current.source2 = (current.input >> 16) & 0x1F;
	current.dest = (current.input >> 11) & 0x1F;
	current.shift = (current.input >> 6) & 0x1F;
	current.funct = (current.input) & 0x3F;
	current.imm = 0;
	current.mem = 0;
}

void i_decode(instruction_t& current){
	/*decoding for i type instructions
	opcode[31-26], source1[25-21], dest[20-16], immediate[15-0]
	*/
	cout << "i_decode" << endl << endl;
	current.source1 = (current.input >> 21) & 0x1F;
	current.source2 = 0;
	current.dest = (current.input >> 16) & 0x1F;
	current.shift = 0;
	current.funct = 0;
	current.imm = (current.input) & 0xFFFF;
	current.mem = 0;
}

void j_decode(instruction_t& current){
	/*decoding for j type instructions
	opcode[31-26], memory[25-0]
	*/
	cout << "j_decode" << endl << endl;
	current.source1 = 0;
	current.source2 = 0;
	current.dest = 0;
	current.shift = 0;
	current.funct = 0;
	current.imm = 0;
	current.mem = (current.input) & 0x3FFFFFF;
}

void opcode_error(){
	cout << "error" << endl;
}
#endif
