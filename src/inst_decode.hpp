#ifndef inst_decode_H
#define inst_decode_H
#include"global.hpp"

err inst_decode(instruction_t& instruction);

itype inst_type(instruction_t& instruction);

void decode_rtype(instruction_t& current);
void decode_itype(instruction_t& current);
void decode_jtype(instruction_t& current);

#endif
