#ifndef error_H
#define error_H

//error structure for functions to return error codes

enum err{
	
	success = 0;
	
	//errors
	err_arg = 1,
	err_handle = 2,
	err_notimplemented = 3,
	err_overflow = 4,
	
	//exceptions
};

#endif