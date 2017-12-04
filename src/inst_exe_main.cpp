#include<iostream>
#include"inst_exe.cpp"
#include"cpu.hpp"
#include"inst_t.hpp"

using namespace std;

int main(){
	do {
		instruction_t current;
		
		void cpu_start();
	
		cout << "enter inst" << endl;
		cin >> hex >> current.input;
	
		execute_inst_type(current);
		

	}
	while(1);
	
	return 0;
}