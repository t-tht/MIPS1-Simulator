#include<iostream>

using namespace std;

uint32_t instruction_in;

instruction_decode(){
		opcode_in = (instruction_in >> 26) & 0x0000003F;
		if(opcode_in == 0){
			r_decode();
		}
		else if(opcode_in == 3 || opcode_in == 4){
			j_decode();
		}
		else if(opcode_in != 0 || opcode_in != 3 || opcode_in != 4){
			i_decode();
		}
		else{
			opcode_error();
		}
}

r_decode(){
	
}

i_decode(){
	
}

j_decode(){
	
}

opcode_error(){
	
}