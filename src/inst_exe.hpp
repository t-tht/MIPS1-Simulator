#ifndef inst_exe_H
#define inst_exe_H
#include"mips.hpp"

err inst_exe(cpu_state_t& current_state, instruction_t& instruction);

err exe_rtype(cpu_state_t& current_state, instruction_t& instruction);
err exe_itype(cpu_state_t& current_state, instruction_t& instruction);
err exe_jtype(cpu_state_t& current_state, instruction_t& instruction);

#endif