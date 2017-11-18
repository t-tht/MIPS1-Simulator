#include <stdio.h>
#include <iostream>
#include <fstream>

#define MEM_size 4294967296


using namespace std;

int main(){
	
	//char memory [MEM_size];
	char* memory  = new char[MEM_size];
	ifstream input( "test.bin", ios::in |ios::binary );
	cout<<input.tellg()<<endl;
	input.read(memory, MEM_size);
	cout<<input.tellg()<<endl;

	//for (int i = MEM_size-1; i>=0; i--){
	//	cout<<memory[i]<<endl;
	//}
	
	return 0;
};