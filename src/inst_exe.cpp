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
		case 0b011010://DIV
		instruction.name = "DIV";
		current_state.lo = ( (int32_t)s1 / (int32_t)s2 );
		current_state.hi = ( (int32_t)s1 % (int32_t)s2 );
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b011011://DIVU
		instruction.name = "DIVU";
		current_state.lo = ( s1 / s2 );
		current_state.hi = ( s1 % s2 );
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b001001://JALR
		instruction.name = "JALR";
		cpu_write_reg(current_state, 31, current_state.npc + 4);
		current_state.pc = current_state.npc;
		current_state.npc = s1;
		return excpt_break;
		break;
		//-----------------------------------------------------------------
		case 0b001000://JR
		instruction.name = "JR";
		current_state.pc = current_state.npc;
		current_state.npc = s1;
		return excpt_break;		//exception so that pc does not increment
		//-----------------------------------------------------------------
		case 0b010000://MFHI
		instruction.name = "MFHI";
		cpu_write_reg(current_state, dest, current_state.hi);
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b010010://MFLO
		instruction.name = "MFLO";
		cpu_write_reg(current_state, dest, current_state.lo);
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b010001://MTHI
		instruction.name = "MTHI";
		current_state.hi = s1;
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b010011://MTLO
		instruction.name = "MTLO";
		current_state.lo = s1;
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b011000://MULT
		instruction.name = "MULT";
		int64_t temp;
		temp = ( ((int64_t)s1)*((int64_t)s2) );
		current_state.lo = (int32_t)(temp&0xffffffff);
		current_state.hi = (int32_t)((temp&0xffffffff00000000)>>32);
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b011001://MULTU
		instruction.name = "MULTU";
		uint64_t tempu;
		temp = ( ((uint64_t)s1)*((uint64_t)s2) );
		current_state.lo = (int32_t)(temp&0xffffffff);
		current_state.hi = (int32_t)((temp&0xffffffff00000000)>>32);
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
		case 0b000100://SLLV
		instruction.name = "SLLV";
		cpu_write_reg(current_state, dest, (s2 << s1));
		return success;
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
		case 0b000110://SRLV
		instruction.name = "SRLV";
		cpu_write_reg(current_state, dest, (s2 >> s1));
		return success;
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
		
		// default:
		// 		std::cout<< "function code not found" << std::endl;
		// 		return err_notimpl;
		// 		break;
		
	};
	return err_unexpct;
}

//select itype instruction
err exe_itype(cpu_state_t& current_state, instruction_t& instruction) {
	uint32_t s1 = instruction.source1;
	uint32_t dest = instruction.dest;
	uint32_t imm = instruction.imm;
	int32_t simm = int32_t(instruction.imm);

	switch(instruction.opcode) {
		//-----------------------------------------------------------------
		case 0b001000:
		//ADDI
		break;
		//-----------------------------------------------------------------
		case 0b001001://ADDIU
		instruction.name = "ADDIU";
		cpu_write_reg(current_state, dest, (s1 + imm));
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b001100://ANDI
		instruction.name = "ANDI";
		cpu_write_reg(current_state, dest, (s1 & imm));
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b000100://BEQ
		instruction.name = "BEQ";
		std::cout << "beq" << std::endl;
		if(s1 == dest) {
			cpu_set_pc(current_state, (imm<<2) );
			return excpt_break;
		}else{
			return success;
		}
		break;
		//-----------------------------------------------------------------
		case 0b0000000: //BGEZ
		instruction.name = "BGEZ";
		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		// 		//BGEZAL
		// 		break;
		//-----------------------------------------------------------------
		case 0b000111: //BGTZ
		instruction.name = "BGTZ";
		if(s1 > 0) {
			cpu_set_pc(current_state, (imm<<2));
			return excpt_break;
		}else{
			return success;
		}
		break;
		//-----------------------------------------------------------------
		case 0b000110: //BLEZ
		instruction.name = "BLEZ";
		if(s1 <= 0) {
			cpu_set_pc(current_state, (imm<<2));
			return excpt_break;
		}else{
			return success;
		}
		break;
		//-----------------------------------------------------------------
		// case 0b0000000: //BLTZ
		// 		instruction.name = "BLTZ";
		// 		if(s1 < 0) {
		// 			cpu_set_pc(current_state, (imm<<2));
		// 			return excpt_break;
		// 		}else{
		// 			return success;
		// 		}
		// 		break;
		//-----------------------------------------------------------------
		// 		case 0b0000000: //incorrect
		//BLTZAL
		break;
		//-----------------------------------------------------------------
		case 0b000101://BNE
		instruction.name = "BNE";
		if(s1 != dest) {
			cpu_set_pc(current_state, (imm<<2));
			return excpt_break;
		}else{
			return success;
		}
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
		cpu_write_reg(current_state, dest, (imm<<16));
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
		cpu_write_reg(current_state, dest, (s1|imm));
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
		case 0b001010://SLTI
		instruction.name = "SLTI";
		if(s1 < simm) {
			cpu_write_reg(current_state, dest, 1);
		}else{
			cpu_write_reg(current_state, dest, 0);
		}
		return success;
		break;
		//-----------------------------------------------------------------
		case 0b001011://SLTIU
		instruction.name = "SLTIU";
		if(s1 < imm) {
			cpu_write_reg(current_state, dest, 1);
		}else{
			cpu_write_reg(current_state, dest, 0);
		}
		return success;
		break;
		//-----------------------------------------------------------------
		// case 0b101001:
		// //SW					//clash with sh
		// break;
		//-----------------------------------------------------------------
		case 0b001110://XORI
		instruction.name = "XORI";
		cpu_write_reg(current_state, dest, (s1 ^ imm));
		break;		
		//-----------------------------------------------------------------
		
		default:
		std::cout<< "invalid I type instruction" << std::endl;
		break;
	}
}

//select jtype instruction
err exe_jtype(cpu_state_t& current_state, instruction_t& instruction) {
	uint32_t mem = instruction.mem;
	switch(instruction.opcode) {
		//-----------------------------------------------------------------
		case 0b000010://J
		instruction.name = "J";
		current_state.pc = current_state.npc;
		current_state.npc = (current_state.pc & 0xf0000000) | (mem << 2);
		return excpt_break;
		break;
		//-----------------------------------------------------------------
		case 0b000011://JAL
		instruction.name = "JAL";
		cpu_write_reg(current_state, 31, current_state.npc + 4);
		current_state.pc = current_state.npc;
		current_state.npc = (current_state.pc & 0xf0000000) | (mem << 2);
		return excpt_break;
		break;
		//-----------------------------------------------------------------
		
		default:
		std::cout<< "invalid J type instruction" << std::endl;
		break;
	}
}






