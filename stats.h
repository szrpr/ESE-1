/******************************************************************************
* Copyright (C) 2025 by Sezer Kılıç - Coursera
*
* Redistribution, modification, or use of this software in source or binary
* forms is permitted as long as this copyright notice is retained. Users are 
* permitted to modify and use this project to learn about embedded software. 
* Sezer Kılıç is not liable for any misuse of this material. 
******************************************************************************/
/**
 * @file stats.h
 * @brief This header file contains functions for performing
 * arithmetic and relational operations on an array..
 * @author Sezer Kılıç
 * @January 29,2025
 */

#ifndef STATS_H
#define STATS_H

#include <stdio.h>

/**
 * @brief Prints the elements of an array.
 *
 * This function takes an array and its length as input and prints
 * each element of the array in order.
 *
 * @param my_array The array to be printed.
 * @param array_length The number of elements in the array.
 * @return void
 */
void print_array(unsigned char my_array[], unsigned int array_length);

/**
 * @brief Prints the calculated statistical values.
 *
 * This function displays the computed median, mean, maximum, and minimum
 * values of the array in a formatted manner.
 *
 * @param median The median value.
 * @param mean The mean (average) value.
 * @param maximum_element The maximum element in the array.
 * @param minimum_element The minimum element in the array.
 * @return void
 */
void print_statics(float median, float mean, unsigned char maximum_element,unsigned char minimum_element);

/**
 * @brief Finds the median of a sorted array.
 *
 * If the array length is odd, it returns the middle element.
 * If the array length is even, it returns the average of the
 * two middle elements.
 *
 * @param my_array The sorted array.
 * @param array_length The number of elements in the array.
 * @return The median value as a float.
 */
float find_median(unsigned char my_array[], unsigned int array_length);

/**
 * @brief Calculates the mean (average) of an array.
 *
 * This function computes the arithmetic mean of all elements in the array.
 *
 * @param my_array The array containing the elements.
 * @param array_length The number of elements in the array.
 * @return The mean value as a float.
 */
float find_mean(unsigned char my_array[], unsigned int array_length);

/**
 * @brief Finds the maximum element in an array.
 *
 * This function iterates through the array and returns the
 * largest value found.
 *
 * @param my_array The array to search.
 * @param array_length The number of elements in the array.
 * @return The maximum element.
 */
unsigned char find_maximum(unsigned char my_array[], unsigned int array_length);

/**
 * @brief Finds the minimum element in an array.
 *
 * This function iterates through the array and returns the smallest value found.
 *
 * @param my_array The array to search.
 * @param array_length The number of elements in the array.
 * @return The minimum element.
 */
unsigned char find_minimum(unsigned char my_array[], unsigned int array_length);

/**
 * @brief Sorts an array in descending order.
 *
 * This function implements the Bubble Sort algorithm to sort an array
 * in descending order (largest to smallest).
 *
 * @param my_array The array to be sorted.
 * @param array_length The number of elements in the array.
 * @return void
 */
void sort_array(unsigned char my_array[], unsigned int array_length);

#endif // STATS_H
