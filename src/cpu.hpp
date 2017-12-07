#ifndef cpu_H
#define cpu_H
#include"mips.hpp"

struct cpu_state_t{
	uint32_t pc;
	uint32_t npc;
	uint32_t lo;
	uint32_t hi;
	uint32_t reg[32];
	
	void debug(){
		std::cout << "+----------------+" << std::endl;
		std::cout <<"|"<< std::hex << "pc:\t" << pc <<"\t|"<< std::endl;
		std::cout <<"|"<< std::hex << "npc:\t" << npc <<"\t|"<< std::endl;
		std::cout <<"|"<< std::hex << "lo:\t" << lo <<"\t|"<< std::endl;
		std::cout <<"|"<< std::hex << "hi:\t" << hi <<"\t|"<< std::endl;
		std::cout << "+----------------+" << std::endl;
		std::cout << "+---------------------------------------+" << std::endl;
		for(int i = 0; i < 32; i++) {
			std::cout<<"|" << std::hex << "register "<< i << ":\t" << reg[i]<<"\t\t\t|" <<std::endl;
		}
		std::cout << "+---------------------------------------+" << std::endl;
	}
};

void cpu_init(cpu_state_t& current_state);

err cpu_set_pc(cpu_state_t& current_state, uint32_t pc);
err cpu_write_reg(cpu_state_t& current_state, uint32_t register_no, uint32_t value);

err cpu_run(cpu_state_t& state);
err cpu_exit();



#endif
