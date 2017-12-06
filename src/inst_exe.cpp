/*
		contains functions that execute the input instructions
*/
#include<iostream>
#include"inst_exe.hpp"

using namespace std;


//select the type of the instruction
err inst_exe(cpu_state_t& current_state, instruction_t& instruction) {
	switch(instruction.type) {
		case R:
		exe_rtype(current_state, instruction);
		break;
		
		case I:
		exe_itype(current_state, instruction);
		break;
		
		case J:
		exe_jtype(current_state, instruction);
		break;
	}
	return success;
}





//select rtype instruction
void exe_rtype(cpu_state_t& current_state, instruction_t& instruction) {
	uint32_t s1 = instruction.source1;
	uint32_t s2 = instruction.source2;
	uint32_t dest = instruction.dest;
	uint32_t shift = instruction.shift;
	
	
	switch(instruction.funct) {
		case 0b100000:
		//ADD
		cpu_write_reg(current_state, dest, (s1+s2) );
		break;
		case 0b100001:
		//ADDU
		break;
		case 0b100100:
		//AND
		break;
		case 0b011010:
		//DIV
		break;
		case 0b011011:
		//DIVU
		break;
		case 0b001001:
		//JALR
		break;
		case 0b001000:
		//JR
		break;
		case 0b010000:
		//MFHI
		break;
		case 0b010010:
		//MFLO
		break;
		case 0b010001:
		//MTHI
		break;
		case 0b010011:
		//MTLO
		break;
		case 0b011000:
		//MULT
		break;
		case 0b011001:
		//MULTU
		break;
		case 0b100101:
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
		
		default:
		std::cout<< "invalid R type instruction" << std::endl;
		break;
		
	};
	
}

//select itype instruction
void exe_itype(cpu_state_t& current_state, instruction_t& instruction) {
	switch(instruction.opcode) {
		case 0b001000:
		//ADDI
		break;
		case 0b001001:
		//ADDIU				//clash with SLTIU
		break;
		case 0b001100:
		//ANDI
		break;
		case 0b000100:
		//BEQ
		break;
		// case 0b0000000: //incorrect
// 		//BGEZ
// 		break;
// 		case 0b0000000: //incorrect
// 		//BGEZAL
// 		break;
// 		case 0b0000000: //incorrect
// 		//BGTZ
// 		break;
// 		case 0b0000000: //incorrect
// 		//BLEZ
// 		break;
// 		case 0b0000000: //incorrect
// 		//BLTZ
// 		break;
// 		case 0b0000000: //incorrect
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
		// case 0b0000000: //incorrect
// 		//LUI
// 		break;
		case 0b100011:
		//LW
		break;
		case 0b100010:
		//LWL
		break;
		case 0b100110:
		//LWR
		break;
		case 0b001101:
		//ORI
		break;
		case 0b101000:
		//SB
		break;
		// case 0b101001:
		// //SH					//clash with sw
		// break;
		case 0b001010:
		//SLTI
		break;
		// case 0b001001:
		// //SLTIU				//clash with ADDIU
		// break;
		// case 0b101001:
		// //SW					//clash with sh
		// break;
		case 0b001110:
		//XORI
		break;		
		
		default:
		std::cout<< "invalid I type instruction" << std::endl;
		break;
	}
}

//select jtype instruction
void exe_jtype(cpu_state_t& current_state, instruction_t& instruction) {
	switch(instruction.opcode) {
		case 0b000010:
		//J
		break;
		case 0b000011:
		//JAL
		break;
		
		default:
		std::cout<< "invalid J type instruction" << std::endl;
		break;
	}
}





