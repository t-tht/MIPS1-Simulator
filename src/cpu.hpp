#ifndef cpu_H
#define cpu_H
#include"error.hpp"



struct cpu_reg{
	uint32_t pc;
	uint32_t npc;
	uint32_t reg[32];
};

cpu_reg currentcpu;
state mips_cpu;

void cpu_start();

void cpu_write_reg(uint32_t register_no, uint32_t value);

void cpu_exit();



#endif
