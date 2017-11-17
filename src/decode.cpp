/*
R type opcode: 000000
I type opcode: XXXXXX
J type opcode: 00001X
*/
#include<string>
#include<iostream>
using namespace std;

int main(){
string opcode_in;
do{
cout << "input opcode" << endl;
cin >> opcode_in;
	
if(opcode_in == "000000"){
	cout << "R" << endl;
}
else if((opcode_in == "000010")||(opcode_in == "000011")){
	cout << "J" << endl;
}
else{
	cout << "I" << endl;
}
}
while(opcode_in != "z");
	
	return 0;
}