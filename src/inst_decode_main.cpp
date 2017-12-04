#include<iostream>
#include<stdlib.h>
#include"inst_exe.cpp"

using namespace std;

int main(){
	bool cont = 1;
	instruction_t current;
	do{
		cout << "________________________________________" << endl;
		cout << endl << "enter the instruction code:	";
		cin >>  hex >> current.input;
		
		execute_inst_type(current);
	
	}
	while(1);
		
	return 0;
}
