simulator : src/*.cpp
	g++ src/*.cpp -o bin/simulator

testbench : bin/testbench.cpp
	g++ bin/testbench.cpp -o bin/mips_testbench.exec
	

