#include<iostream>
#include"inst_exe.hpp"
#include"inst_decide.cpp"

using namespace std;


//find the type of instruction
itype inst_type(instruction_t& current) {

	current.opcode = (current.input >> 26) & 0x3F ;
	
	if(current.opcode == 0){
		return R;
	}
	else if(current.opcode == 3 || current.opcode == 4){
		return J;
	}
	else if(current.opcode != 0 || current.opcode != 3 || current.opcode != 4){
		return I;
	}
}







//select the type of the instruction
void execute_inst_type(instruction_t& current) {
	
	itype current_type = inst_type(current);

	switch(current_type) {
		case R:
		execute_rtype(current);
		break;
		
		case I:
		execute_itype(current);
		break;
		
		case J:
		execute_jtype(current);
		break;
	}
}





//select rtype instruction
void execute_rtype(instruction_t& current) {
	cout << "rtype success" << endl;
	decode_rtype(current);
	switch(current.funct) {
		//rtype instructions
	};
	
}

//select itype instruction
void execute_itype(instruction_t& current) {
	cout << "itype success" << endl;
	decode_itype(current);
	switch(current.funct) {
		//itype instructions
	}
}

//select jtype instruction
void execute_jtype(instruction_t& current) {
	cout << "jtype success" << endl;
	decode_jtype(current);
	//jtype instructions
}





