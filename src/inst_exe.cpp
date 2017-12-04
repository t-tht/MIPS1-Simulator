#include<iostream>
#include"inst_exe.hpp"
#include"inst_decide.cpp"

using namespace std;


//find the type of instruction
itype inst_type(instruction_t& current) {

	current.opcode = (current.input >> 26) & 0x3F ;
	
	if(current.opcode == 0){
		return R;
	}
	else if(current.opcode == 3 || current.opcode == 4){
		return J;
	}
	else if(current.opcode != 0 || current.opcode != 3 || current.opcode != 4){
		return I;
	}
}







//select the type of the instruction
void execute_inst_type(instruction_t& current) {
	
	itype current_type = inst_type(current);

	switch(current_type) {
		case R:
		execute_rtype(current);
		break;
		
		case I:
		execute_itype(current);
		break;
		
		case J:
		execute_jtype(current);
		break;
	}
}





//select rtype instruction
void execute_rtype(instruction_t& current) {
	cout << "rtype success" << endl;
	decode_rtype(current);
	switch(current.funct) {
		case:0b100000:
		//ADD
		break;
		case:0b100001:
		//ADDU
		break;
		case:0b100100:
		//AND
		break;
		case:0b011010:
		//DIV
		break;
		case:0b011011:
		//DIVU
		break;
		case:0b001001:
		//JALR
		break;
		case:0b001000:
		//JR
		break;
		case:0b010000:
		//MFHI
		break;
		case:0b010010:
		//MFLO
		break;
		case:0b010001:
		//MTHI
		break;
		case:0b010011:
		//MTLO
		break;
		case:0b011000:
		//MULT
		break;
		case:0b011001:
		//MULTU
		break;
		case 0b:100101:
		//OR
		break;
		case 0b000000:
		//SLL
		break;
		case 0b000100:
		//SLLV
		break;
		case 0b101010:
		//SLT
		break;
		case 0b101001:
		//SLTU
		break;
		case 0b000011:
		//SRA
		break;
		case 0b000111:
		//SRAV
		break;
		case 0b000010:
		//SRL
		break;
		case 0b000110:
		//SRLV
		break;
		case 0b100010:
		//SUB
		break;
		case 0b100011:
		//SUBU
		break;
		case 0b100110:
		//XOR
		break;
		
	};
	
}

//select itype instruction
void execute_itype(instruction_t& current) {
	cout << "itype success" << endl;
	decode_itype(current);
	switch(current.opcode) {
		case 0b001000:
		//ADDI
		break;
		case 0b001001:
		//ADDIU
		break;
		case 0b001100:
		//ANDI
		break;
		case 0b000100:
		//BEQ
		break;
		case 0b:
		//BGEZ
		break;
		case 0b:
		//BGEZAL
		break;
		case 0b:
		//BGTZ
		break;
		case 0b:
		//BLEZ
		break;
		case 0b:
		//BLTZ
		break;
		case 0b:
		//BLTZAL
		break;
		case 0b000101:
		//BNE
		break;
		case 0b100000:
		//LB
		break;
		case 0b100100:
		//LBU
		break;
		case 0b100001:
		//LH
		break;
		case 0b100101:
		//LHU
		break;
		case 0b:
		//LUI
		break;
		case 0b100011:
		//LW
		break;
		case 0b:100010:
		//LWL
		break;
		case 0b:100110:
		//LWR
		break;
		case 0b001101:
		//ORI
		break;
		case 0b101000:
		//SB
		break;
		case 0b:101001:
		//SH
		break;
		case 0b001010:
		//SLTI
		break;
		case 0b001001:
		//SLTIU
		break;
		case 0b101001:
		//SW
		break;
		case 0b:001110:
		//XORI
		break;		
	}
}

//select jtype instruction
void execute_jtype(instruction_t& current) {
	cout << "jtype success" << endl;
	decode_jtype(current);
	
	switch(current.opcode) {
		case 0b000010:
		//J
		break;
		case 0b000011:
		//JAL
		break;
	}
}





