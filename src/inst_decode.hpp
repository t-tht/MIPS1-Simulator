#ifndef inst_decode_H
#define inst_decode_H

#include"inst_t.hpp"

using namespace std;

//separate instrunction into different parts
void decode_rtype(instruction_t& current);
void decode_itype(instruction_t& current);
void decode_jtype(instruction_t& current);

void instruction_decode(instruction_t current);

#endif
