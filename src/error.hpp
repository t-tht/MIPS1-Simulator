#ifndef error_H
#define error_H

#include "global.hpp"
//error structure for functions to return error codes

enum err{
	
	success = 0,
	
	//errors
	err_arg = 1,
	err_handle = 2,
	err_notimpl = 3,
	err_overflow = 4,
	err_unexpct,
	
	//exceptions
	
	excpt_break = 5,
};

#endif