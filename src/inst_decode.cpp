/*
includes functions that decodes the input functions and put information into struct instruction_t (in "inst_t.hpp").
*/
#include<iostream>
#include"inst_decode.hpp"

using namespace std;


//main function of instruction decoding
err inst_decode(instruction_t& instruction) {
	instruction.type = inst_type(instruction);
	switch(instruction.type) {
		case R:
		decode_rtype(instruction);
		break;
		
		case I:
		decode_itype(instruction);
		break;
		
		case J:
		decode_jtype(instruction);
		break;
	}
	return success;
}
//main function of instruction decoding




//returns the type of instruction
itype inst_type(instruction_t& instruction) {

	instruction.opcode = (instruction.input >> 26) & 0x3F ;
	
	if(instruction.opcode == 0){
		return R;
	}
	else if(instruction.opcode == 3 || instruction.opcode == 4){
		return J;
	}
	else if(instruction.opcode != 0 || instruction.opcode != 3 || instruction.opcode != 4){
		return I;
	}
	else{
		std::cout<<"error identifying instruction type!" << std::endl;
		return I;
	}
}

void decode_rtype(instruction_t& instruction){			
	/*decoding for r type instructions
	opcode[31-26], source1[25-21], source2[20-16], dest[15-11], shift[10-6], funct[5-0]
	*/
	cout << "r_decode" << endl << endl;
	instruction.source1 = (instruction.input >> 21) & 0x1F;
	instruction.source2 = (instruction.input >> 16) & 0x1F;
	instruction.dest    = (instruction.input >> 11) & 0x1F;
	instruction.shift   = (instruction.input >> 6) & 0x1F;
	instruction.funct   = (instruction.input) & 0x3F;
	instruction.imm     = 0;
	instruction.mem     = 0;
}

void decode_itype(instruction_t& instruction){
	/*decoding for i type instructions
	opcode[31-26], source1[25-21], dest[20-16], immediate[15-0]
	*/
	cout << "i_decode" << endl << endl;
	instruction.source1 = (instruction.input >> 21) & 0x1F;
	instruction.source2 = 0;
	instruction.dest    = (instruction.input >> 16) & 0x1F;
	instruction.shift   = 0;
	instruction.funct   = 0;
	instruction.imm     = (instruction.input) & 0xFFFF;
	instruction.mem     = 0;
}

void decode_jtype(instruction_t& instruction){
	/*decoding for j type instructions
	opcode[31-26], memory[25-0]
	*/
	cout << "j_decode" << endl << endl;
	instruction.source1 = 0;
	instruction.source2 = 0;
	instruction.dest    = 0;
	instruction.shift   = 0;
	instruction.funct   = 0;
	instruction.imm     = 0;
	instruction.mem     = (instruction.input) & 0x3FFFFFF;
}
