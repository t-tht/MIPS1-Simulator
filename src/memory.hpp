#ifndef memory_H
#define memory_H
#include"error.hpp"
#include"stdlib.h"

// #define MEM_SIZE 4294967296
//
// uint8_t memarray[MEM_SIZE];
// uint8_t * memptr;
//
// memarray = memptr;

err mem_init(uint8_t* mem);
err mem_read(uint32_t index, uint8_t value);
err mem_write(uint32_t index, uint8_t value);
err mem_clear(uint32_t index);

#endif

