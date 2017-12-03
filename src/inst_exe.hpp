#ifndef inst_exe_H
#define inst_exe_H

#include"inst_t.hpp"

//find inst type, returns enum itype(R,I,J)
itype inst_type(instruction_t& current);

//selector for instruction type
void execute_inst_type(instruction_t& current);

void execute_rtype(instruction_t& current);
void execute_itype(instruction_t& current);
void execute_jtype(instruction_t& current);




#endif