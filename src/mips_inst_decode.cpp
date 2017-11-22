#include<iostream>
#include"mips_inst_decode.hpp"

using namespace std;


void instruction_decode(instruction_t current){	
	 current.opcode = (current.input >> 26) & 0x3F ;
		
	if(current.opcode == 0){
		r_decode(current);
		current.debug();
	}
	else if(current.opcode == 3 || current.opcode == 4){
		j_decode(current);
		current.debug();
	}
	else if(current.opcode != 0 || current.opcode != 3 || current.opcode != 4){
		i_decode(current);
		current.debug();
	}
	else{
		opcode_error();
	}
		
}
