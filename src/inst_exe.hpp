#ifndef inst_exe_H
#define inst_exe_H

#include"inst_t.hpp"
#include"error.hpp"

err inst_exe(instruction_t& instruction);

void exe_rtype(instruction_t& current);
void exe_itype(instruction_t& current);
void exe_jtype(instruction_t& current);

#endif