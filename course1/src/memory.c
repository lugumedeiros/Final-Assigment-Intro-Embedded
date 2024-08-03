/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
/*This function will move a block of size <lenght> from src to dst addresses
  src has the address of the first item to be moved and dst has the address 
  of the first item that will be moved if fronwarded. */
  
  uint8_t* dstcopy = dst;
  //backward memmory movement
  if (src + length > dst) {
    src += (length - 1);
    dst += (length - 1);
    while(length--){
      *dst = *src;
      --dst;
      --src;
    }
  } 
  //forward memory movement
  else {
    while (length--){
      *dst = *src;
      ++dst;
      ++src;
    }
  }
  return dstcopy;
}

uint8_t *my_memcopy(uint8_t* src, uint8_t* dst, size_t length) {
/*This funciton does the same as my_memmove (move a block of data), but it will
  not test if it's a safe operation, forward movement always*/
  
  uint8_t* dstcopy = dst;
  //frontward memory movement
    while (length--){
      *dst = *src;
      ++dst;
      ++src;
  }
  return dstcopy;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
//this function will set all values inside the selected memory to <value>

  uint8_t* srctemp = src;
  while(length--) {
    *src = value;
    ++src;
  }
  //src = srctemp;
  return srctemp;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  /* This function will use memset as base to set all values to zero,
    the return of this fucntion is the start of the same*/
  
  uint8_t set_zero = 0;
  my_memset(src, length, set_zero);
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
  /* This function reverses all values inside of the selected memory, even or 
    odd. This is achieved by swapping from outer pairs to the inner one */
  
  uint8_t* start = src;
  uint8_t* end = src + length - 1;
  uint8_t temp;

  while (start < end) {
    //swapping
    temp = *src;
    *start = *end;
    *end = temp;

    //pointer movement
    ++start;
    --end;
  }
  return src;
}

int32_t * reserve_words(size_t length) {
/* Creates a malloc of length size */

  size_t size_bytes = length * sizeof(int32_t);
  int32_t* ptr = (int32_t *)malloc(size_bytes);
  return ptr;
}

void free_words(int32_t * src){
/* Frees a malloc */
  free (src);
  src = NULL;
}