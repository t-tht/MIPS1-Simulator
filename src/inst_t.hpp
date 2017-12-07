#ifndef inst_H
#define inst_H
#include<string>

enum itype {R, I, J};

struct instruction_t {
	//define a struct for instruction that includes the different components of an instruction input
	uint32_t input;
	itype type;
	std::string name;
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
	std::cout << "+------instruction-------+" << std::endl;
	std::cout <<  "|input:\t\t" << input << "\t |"<<std::endl;
	std::cout <<  "|type:\t\t" << type << "\t |"<<std::endl;
	std::cout <<  "|name:\t\t" << name << "\t |"<<std::endl;
	std::cout <<  "|opcode:\t" << opcode << "\t |"<<std::endl;
	std::cout <<  "|source1:\t" << source1 << "\t |"<<std::endl;
	std::cout <<  "|source2:\t" << source2 << "\t |"<<std::endl;
	std::cout <<  "|dest:\t\t" << dest << "\t |"<<std::endl;
	std::cout <<  "|shift:\t\t" << shift << "\t |"<<std::endl;
	std::cout <<  "|funct:\t\t" << funct << "\t |"<<std::endl;
	std::cout <<  "|immediate:\t" << imm << "\t |"<<std::endl;
	std::cout <<  "|memory:\t" << mem << "\t |"<<std::endl;
	std::cout << "+------------------------+" << std::endl;
}


#endif