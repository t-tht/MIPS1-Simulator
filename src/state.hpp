#ifndef state_H
#define state_H

using namespace std;


enum cpu_state{
	//types of error with their assigned values
	error_success = 0, 
	error_inv_arg = 1,
	error_inv_handle = 2
};


#endif