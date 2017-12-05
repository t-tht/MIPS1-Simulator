#ifndef memory_H
#define memory_H
#include"error.hpp"

struct mem_t{
	
};
err mem_create();
err mem_read(index, value);
err mem_write(index, value);
err mem_clear(index);

#endif