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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdio.h>
#include "stats.h"
#include <stdbool.h> // for bool data type
#include <stdlib.h> // for qsort() 


/* Add Your Declarations and Function Comments here */ 

unsigned char find_maximum (unsigned char array[], unsigned int size);
/*  find_maximum will iterate on every value of the array and then give
    the maximum value found. */

unsigned char find_minimum (unsigned char array[], unsigned int size);
/* find_minimum will iterate on every value of the array and then give
   the minimum value found. */

double find_mean_double (unsigned char array[], unsigned int size);
/* find_mean_double will iterate and sum every value of the array, at
   the end will return mean value found.
   This is a float point operation for precision, if your system has no
   support for this kind of operation, use find_mean()*/

int find_mean (unsigned char array[], unsigned int size,
                        bool allow_round);
    /* find_mean will iterate and sum every value of the array, at the
   end will return mean value found.
   This is not a precision function, set allow_round for one decimal precision
   if necessary, otherwise no round up will occur.*/

int compare(const void *a, const void *b);
void sort_array(unsigned char array[], unsigned int size);
/*  This function will sort the array using compare() and qsort() */

unsigned char find_median (unsigned char array[], unsigned int size);  
/*  find_median will test if array is already sorted, if not, then it will use
    sort_array() and then finally evaluate median value. */

void print_array(unsigned char array[], unsigned int size);    
/*  simple function that will print array to screen */

void print_statistics(unsigned char array[], unsigned int size, bool alow_float);        
/**
 * @brief print_statistics() will printf median, mean, minimum and maximum for
 *        a given unsigned char array.
 *
 * Every function in this header has the main objective of being used in
 * print_statistics, but everything can be used as a standalone function.
 * The function has two modes:
 * - alow_float=true will end in a double function meaning greater precision.
 * - alow_float=false will end in an int function with one decimal round up
 * if necessary, this round up can be turned off on stats.c
 * 
 * This was made in this way for uses in systems without proper float
 * functions, but it's properties must be commented out to be compiled in such
 * machines.
 * 
 * @param array unsigned char array that user will use
 * @param size  size of the array
 * @param alow_float turn onn/off float mean
 *
 * @return Has only printf, no return.
 */


#endif /* __STATS_H__ */
