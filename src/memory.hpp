#ifndef memory_H
#define memory_H
#include"error.hpp"
#include"stdlib.h"
#include <stdint.h>
#include <stdio.h>

// #define MEM_SIZE 4294967296
//
// uint8_t memarray[MEM_SIZE];
// uint8_t * memptr;
//
// memarray = memptr;

err mem_print(unsigned char ROM[], size_t bytes);
uint32_t mem_instruction(unsigned char ROM[], uint32_t pc);
err mem_read(unsigned char ROM[], uint32_t index, uint8_t& value);
err mem_write(unsigned char ROM[], uint32_t index, uint8_t value);
err mem_clear(unsigned char ROM[], uint32_t index);

#endif

