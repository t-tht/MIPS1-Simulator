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
err exe_rtype(cpu_state_t& current_state, instruction_t& instruction) {
	uint32_t s1 = instruction.source1;
	uint32_t s2 = instruction.source2;
	uint32_t dest = instruction.dest;
	uint32_t shift = instruction.shift;
	
	
	switch(instruction.funct) {
		//-----------------------------------------------------------------
		case 0b100000://ADD
		//if(CHECK FOR OVERFLOW){
		cpu_write_reg(current_state, dest, (s1+s2));
		//}
		break;
		//-----------------------------------------------------------------
		case 0b100001://ADDU
		cpu_write_reg(current_state, dest, (s1+s2) );
		break;
		//-----------------------------------------------------------------
		case 0b100100://BITWISE AND
		cpu_write_reg(current_state, dest, (s1&s2) );
		break;
		//-----------------------------------------------------------------
		case 0b011010:
		//DIV
		break;
		//-----------------------------------------------------------------
		case 0b011011:
		//DIVU
		break;
		//-----------------------------------------------------------------
		case 0b001001:
		//JALR
		break;
		//-----------------------------------------------------------------
		case 0b001000://JR
		current_state.pc = current_state.npc;
		current_state.npc = s1;
		return excpt_break;		//exception so that pc does not increment
		//-----------------------------------------------------------------
		case 0b010000:
		//MFHI
		break;
		//-----------------------------------------------------------------
		case 0b010010:
		//MFLO
		break;
		//-----------------------------------------------------------------
		case 0b010001:
		//MTHI
		break;
		//-----------------------------------------------------------------
		case 0b010011:
		//MTLO
		break;
		//-----------------------------------------------------------------
		case 0b011000:
		//MULT
		break;
		//-----------------------------------------------------------------
		case 0b011001:
		//MULTU
		break;
		//-----------------------------------------------------------------
		case 0b100101://OR
		instruction.name = "OR";
		cpu_write_reg(current_state, dest, (s1|s2) ); 
		break;
		//-----------------------------------------------------------------
		case 0b000000://SLL
		instruction.name = "SLL";
		cpu_write_reg(current_state, dest, (s2<<shift) );
		break;
		//-----------------------------------------------------------------
		case 0b000100:
		//SLLV
		break;
		//-----------------------------------------------------------------
		case 0b101010://SLT
		instruction.name = "SLT";
		if(int32_t(s1) < int32_t(s2)){
			cpu_write_reg(current_state, dest, 1);
		}else{
			cpu_write_reg(current_state, dest, 0);
		}
		break;
		//-----------------------------------------------------------------
		case 0b101011://SLTU
		instruction.name = "SLTU";
		if(s1 < s2) {
			cpu_write_reg(current_state, dest, 1);
		}else{
			cpu_write_reg(current_state,dest, 0);
		}
		break;
		//-----------------------------------------------------------------
		case 0b000011://SRA
		instruction.name = "SRA";
		cpu_write_reg(current_state, dest, (((int32_t) s2) >> shift) );// the >> operator is arithmetic when s2 is signed, and logical when it is unsigned
		break;
		//-----------------------------------------------------------------
		case 0b000111://SRAV
		instruction.name = "SRAV";
		cpu_write_reg(current_state, dest, (((int32_t) s2) >> s1) );
		break;
		//-----------------------------------------------------------------
		case 0b000010://SRL
		instruction.name = "SRL";
		cpu_write_reg(current_state, dest, (s2 >> shift));
		break;
		//-----------------------------------------------------------------
		case 0b000110:
		//SRLV
		break;
		//-----------------------------------------------------------------
		case 0b100010://SUB
		instruction.name = "SUB";
		if(1){
			cpu_write_reg(current_state, dest, (s2 - s1));
		}
		break;
		//-----------------------------------------------------------------
		case 0b100011://SUBU
		instruction.name = "SUBU";
		cpu_write_reg(current_state, dest, (s1-s2) );
		break;
		//-----------------------------------------------------------------
		case 0b100110://XOR
		instruction.name = "XOR";
		cpu_write_reg(current_state, dest, (s1^s2) );
		break;
		//-----------------------------------------------------------------
		
		default:
		std::cout<< "function code not found" << std::endl;
		return err_notimpl;
		break;
		
	};
	return err_unexpct;
}

//select itype instruction
err exe_itype(cpu_state_t& current_state, instruction_t& instruction) {
	uint32_t s1 = instruction.source1;
	uint32_t dest = instruction.dest;
	uint32_t uimm = instruction.imm;
	int32_t simm = int32_t(instruction.imm);

	switch(instruction.opcode) {
		//-----------------------------------------------------------------
		case 0b001000:
		//ADDI
		break;
		//-----------------------------------------------------------------
		case 0b001001://ADDIU CLASH WITH SLTIU
		instruction.name = "ADDIU";
		cpu_write_reg(current_state, dest, (s1 + uimm));
		break;
		//-----------------------------------------------------------------
		case 0b001100://ANDI
		instruction.name = "ANDI";
		cpu_write_reg(current_state, dest, (s1 & uimm));
		break;
		//-----------------------------------------------------------------
		case 0b000100:
		//BEQ
		break;
		//-----------------------------------------------------------------
		// case 0b0000000: //incorrect
		// 		//BGEZ
		// 		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		// 		//BGEZAL
		// 		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		// 		//BGTZ
		// 		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		// 		//BLEZ
		// 		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		// 		//BLTZ
		// 		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		//BLTZAL
		break;
		//-----------------------------------------------------------------
		case 0b000101:
		//BNE
		break;
		//-----------------------------------------------------------------
		case 0b100000:
		//LB
		break;
		//-----------------------------------------------------------------
		case 0b100100:
		//LBU
		break;
		//-----------------------------------------------------------------
		case 0b100001:
		//LH
		break;
		//-----------------------------------------------------------------
		case 0b100101:
		//LHU
		break;
		//-----------------------------------------------------------------
		case 0b001111: //LUI
		instruction.name = "LUI";
		cpu_write_reg(current_state, dest, (uimm<<16));
		break;
		//-----------------------------------------------------------------
		case 0b100011: //LW
		instruction.name = "LW";
		break;
		//-----------------------------------------------------------------
		case 0b100010:
		//LWL
		break;
		//-----------------------------------------------------------------
		case 0b100110:
		//LWR
		break;
		//-----------------------------------------------------------------
		case 0b001101://ORI
		instruction.name = "ORI";
		cpu_write_reg(current_state, dest, (s1|uimm));
		break;
		//-----------------------------------------------------------------
		case 0b101000:
		//SB
		break;
		//-----------------------------------------------------------------
		// case 0b101001:
		// //SH					//clash with sw
		// break;
		//-----------------------------------------------------------------
		case 0b001010:
		//SLTI
		break;
		//-----------------------------------------------------------------
		// case 0b001001:
		// //SLTIU				//clash with ADDIU
		// break;
		//-----------------------------------------------------------------
		// case 0b101001:
		// //SW					//clash with sh
		// break;
		//-----------------------------------------------------------------
		case 0b001110://XORI
		instruction.name = "XORI";
		cpu_write_reg(current_state, dest, (s1 ^ uimm));
		break;		
		//-----------------------------------------------------------------
		
		default:
		std::cout<< "invalid I type instruction" << std::endl;
		break;
	}
}

//select jtype instruction
err exe_jtype(cpu_state_t& current_state, instruction_t& instruction) {
	switch(instruction.opcode) {
		//-----------------------------------------------------------------
		case 0b000010:
		//JƒXORI
		break;
		//-----------------------------------------------------------------
		case 0b000011:
		//JAL
		break;
		//-----------------------------------------------------------------
		
		default:
		std::cout<< "invalid J type instruction" << std::endl;
		break;
	}
}






