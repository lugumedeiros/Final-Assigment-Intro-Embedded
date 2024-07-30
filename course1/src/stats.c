#include <stdio.h>
#include "stats.h"
#include <stdbool.h> // for bool data type
#include <stdlib.h> // for qsort() 

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
    
    print_statistics(test, SIZE, true);
    print_array(test, SIZE);
    
}

/* Add other Implementation File Code Here */
unsigned char find_maximum (unsigned char array[], unsigned int size) {
/*  find_maximum will iterate on every value of the array and then give
    the maximum value found. */
      
    unsigned char max_value_found = array[0];
    
    for (unsigned int i = 1; i < size; i++) {
      max_value_found =
        (array[i] > max_value_found) ? array[i] : max_value_found;
    }
    
    return max_value_found;
}

unsigned char find_minimum (unsigned char array[], unsigned int size) {
/* find_minimum will iterate on every value of the array and then give
   the minimum value found. */
      
    unsigned char min_value_found = array[0];
    
    for (unsigned int i = 1; i < size; i++) {
      min_value_found =
        (array[i] < min_value_found) ? array[i] : min_value_found;
    }
    return min_value_found;
}

double find_mean_double (unsigned char array[], unsigned int size) {
/* find_mean_double will iterate and sum every value of the array, at
   the end will return mean value found.
   This is a float point operation for precision, if your system has no
   support for this kind of operation, use find_mean()*/
   
    unsigned int sum = 0;
    
    for (unsigned int i = 0; i < size; i++) {
       sum += array[i];
       //printf("i = %d, and sum = %d \n",array[i], sum);
    }
    double mean_value = (double)sum / (double)size;
    return mean_value;
}

int find_mean (unsigned char array[], unsigned int size,
                        bool allow_round) {
/* find_data_mean will iterate and sum every value of the array, at the
   end will return mean value found.
   This is not a precision function, set allow_round for one decimal precision
   if necessary, otherwise no round up will occur.*/
   
   unsigned int sum = 0;
   
   for (unsigned int i = 0; i < size; i++) {
       sum += array[i];
   }
   int mean_value = sum / size;
   
   int sum_remainder = sum % size;
   if (sum_remainder > 0 && allow_round) {
       unsigned int half_size = size/2;
       if (sum_remainder > half_size) {
           ++mean_value;
       }
   }
   return mean_value;
}

int compare(const void *a, const void *b) {
    unsigned char char_a = *(unsigned char *)a;
    unsigned char char_b = *(unsigned char *)b;
    return (char_a > char_b) - (char_a < char_b);
}

void sort_array(unsigned char array[], unsigned int size) {
/*  This function will sort the array using compare() and qsort() */
    qsort(array, size, sizeof(char), compare);
}

unsigned char find_median (unsigned char array[], unsigned int size){
/*  find_median will test if array is already sorted, if not, then it will use
    sort_array() and then finally evaluate median value. */
    
    bool is_array_sorted = true;
    for (unsigned int i = 1; i < (size-1); i++) {
        if (array[i] > array[i+1]) {
            is_array_sorted = false;
        }
    }
    if (!is_array_sorted) {
        qsort(array, size, sizeof(char), compare);
    }
    unsigned int half_size = size/2;
    unsigned char median = array[half_size];
    return median;
}

void print_array(unsigned char array[], unsigned int size) {
/*  simple function that will print arrey to screen */
    printf("Array: [ ");
    for (unsigned int i = 0; i < size; i++) {
        printf("%d ",array[i]);
    }
    printf("]\n");
}

void print_statistics(unsigned char array[], unsigned int size, bool alow_float){
    
/*  This function will print all the available statistics for this program*/
    unsigned array_size = size;
    unsigned char max_value = find_maximum(array, array_size);
    unsigned char min_value = find_minimum(array, array_size);
    printf("Maximum: %d\nMinimum: %d\n", max_value,
          min_value);
    
    if (alow_float) {
        double mean_value_double = find_mean_double(array, array_size);
        printf("Mean: %lf\n", mean_value_double);
    } else {
        unsigned int mean_value_int = find_mean(array, array_size, true);
        printf("Mean: %d\n", mean_value_int);
    }
    unsigned int median_value = find_median(array, array_size);
    printf("Median: %d\n", median_value);

}