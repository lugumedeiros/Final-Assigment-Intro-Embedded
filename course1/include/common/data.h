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
 * @file data.h
 * @brief Operations with data in memory
 *
 * This header file provides functions to manipulate data in memory
 *
 * @author Luiz Gustavo de Medeiros
 * @date 03 aug 2024
 *
 */
#ifndef __DATA_H__
#define __DATA_H__


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
/**
 * This function will get a value <data> and use it to transform into an ASCII
 * representation for each digit. Exemple: int x = 123 will become '1','2','3'
 * 
 * @param data Integer value to be used 
 * @param ptr address in memory
 * @param base base to be used. ex.: binary, hex, decimal
 * 
 * @return length of the converted int
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
/**
 * This function will do the same as itoa but inversed, from ASCII
 * representation to int. Exemple '1', '2', '3', will become int 123.
 * 
 * @param ptr address in memory
 * @param digits amount of digits (addresses)
 * @param base base to be used. ex.: binary, hex, decimal
 * 
 * @return converted int
 */

#endif