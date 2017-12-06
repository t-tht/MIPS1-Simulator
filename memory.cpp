#include <iostream>
#include <fstream>
#include <cstring>
#include <stdint.h>
#include <stdlib.h>
#define mem_size 83886092
#define size 3
 

using namespace std;

int main(int argc, char *argv[]){
	
		
	//char* in_ints  = new char[100]; // allocate memory to avoid segmentation fault

	
	
	
	
	ifstream 	r("test.bin", ios::binary);
	int i;
	//uint8_t in_ints[100]; works but obviously to small
	//uint8_t *in_ints = new uint8_t[mem_size]; doesnt work
	//uint8_t *in_ints = (uint8_t*)malloc(sizeof(uint8_t) * mem_size); doesn't work
 	//uint8_t in_ints[mem_size]; doesn't work 
	r.read((char*)&in_ints, sizeof(in_ints)); //takeas in binary file full of 0xFF
	
	
	for(i = 0;i < 10;i++) {  // test to see if array if full of 0xFF
		if(in_ints[i]==0xff){
			cout <<"yes" << " ";
		}else if(in_ints[i]!=0xff){
			cout<<"no"<<" ";
		}
	}
	cout << endl;

	return 0;
		
}
			