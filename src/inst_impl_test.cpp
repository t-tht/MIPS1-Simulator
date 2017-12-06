#include<iostream>
#include"cpu.cpp"

int main(){
	cpu_state_t current_state;
	bool yn;
	do{
		cpu_run(current_state);
		cout << "again?\t(1/0):";
		cin >> yn;		
	}
	while(yn);
	
	return 0;
}