#include<iostream>
// #include"memory.cpp"
using namespace std;

#define MEM_SIZE 4294967296

int main() {
	
	// int memarray[MEM_SIZE];
	// the above array size is too big

	// int* memarray = new int[MEM_SIZE];

	uint8_t memarray[100];

	uint8_t* memptr;
	memptr = memarray;

	for(int i = 0; i < 100; i++) {
		memarray[i] = i;
	}

	cout << "Address: \t\tvalue:"<< endl;

	for(int i = 0; i < 100; i++) {
		cout << memptr[i]<< " \t\t" << memptr[i] << endl;
	}

	// delete [] memarray;
	
	return 0;
}