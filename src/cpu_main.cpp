#include<iostream>
#include"cpu.hpp"

using namespace std;

int main(){
	
	cpu_start();
	
	for(int i = 1; i < 32; i++){
		cpu_write_reg(i,i);
	}
	
	for(int i = 1; i < 32; i++){
		cout << current.reg[i] << endl;
		cout << current.pc << "	" << current.npc << endl;
	}
	
	return 0;
}