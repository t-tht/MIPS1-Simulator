#include<iostream>
#include"cpu.cpp"
using namespace std;

int main(){
	
			cpu_state_t cpustate;
	do{
		
		cpu_run(cpustate);
		
	}
	while(1);
	
	return 0;
}