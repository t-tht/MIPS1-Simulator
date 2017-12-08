#include<iostream>
#include"cpu.cpp"

int main(){
	cpu_state_t current_state;
	cpu_init(current_state);
	
	do{
		cpu_run(current_state);
		std::cout<< "finished running 1 cycle" << std::endl;
		
	}
	while(1);
	
	return 0;
}