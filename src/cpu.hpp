#ifndef cpu_H
#define cpu_H
#include"error.hpp"



struct cpu_state_t{
	uint32_t pc;
	uint32_t npc;
	uint32_t hi;
	uint32_t lo;
	uint32_t reg[32];
	err error;
};

void cpu_start();

void cpu_set_pc(cpu_state_t current_state, uint32_t pc);
err cpu_write_reg(cpu_state_t current_state, uint32_t register_no, uint32_t value);

err cpu_run(cpu_state_t state);
err cpu_exit();



#endif
