/*
	CONTAINS ERROR AND EXCEPTION
*/
#ifndef mips_error_H
#define mips_error_H

using namespace std;

enum error_type{
	//types of error with their assigned values
	error_success = 0, 
	error_inv_arg = 1,
	error_inv_handle = 2
};

#endif