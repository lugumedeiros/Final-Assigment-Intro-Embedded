/*****************************************************************************/
/**
 * @file data.c
 * @brief 
 *
 * @author Luiz Gustavo de Medeiros
 * @date Aug 02 2024
 *
 */

#include "data.h"
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    
    uint8_t * ptr_start = ptr;
    uint8_t length = 0;
    
    uint8_t is_negative = 0;
    if (data < 0 && base == 10) {
        ++length;
        is_negative = 1;
        data *= -1;
    } 
    
    if (data == 0) {
        *ptr = '0';
        ++ptr;
        *ptr = '\0';
        return 2;
    }
    
    //starts with null because it will be reversed.
    //maybe it's better to add after reversing it, idk.
    *ptr = '\0';
    ++ptr;

    while (data > 0) {
        uint8_t remainder = data % base;

        if (remainder < 10) {
        *ptr = remainder + '0'; // Convert remainder 0-9 to '0'-'9'
        } else {
        *ptr = remainder - 10 + 'A'; // Convert remainder 10-15 to 'A'-'F'
        }

        ++ptr;
        data = data / base;
        ++length;
    }

    if (is_negative) {
        *ptr = '-';
        ++ptr;
        ++length;
    }

    my_reverse(ptr_start, length);
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    //uint8_t ptr_start = ptr;
    //uint8_t digits_start = digits;
    uint32_t sum = 0;

    uint8_t is_negative = 0;
    if (*ptr == '-') {
        is_negative = 1;
        ++ptr;
        --digits;
    }

    while (digits) {
        uint32_t current_value = 0;
        if (*ptr >= 'A') {
            current_value = *ptr + 10 - 'A';
        } else {
            current_value = *ptr - '0';
        }
        ++ptr;

        for (uint8_t i = 1; i < digits; i++) {
            current_value *= base;
        }
        sum += current_value;
        --digits;
    }

    if (is_negative) {
        sum *= -1;
    }
    return sum;
}