/******************************************************************************
* Copyright (C) 2025 by Sezer Kılıç - Coursera
*
* Redistribution, modification, or use of this software in source or binary
* forms is permitted as long as this copyright notice is retained. Users are 
* permitted to modify and use this project to learn about embedded software. 
* Sezer Kılıç is not liable for any misuse of this material. 
******************************************************************************/
/**
 * @file stats.c
 * @brief This source file receives char type data input
 *  from the user and prints the operations performed by the
 * functions on the screen.
 * arithmetic and relational operations on an array..
 * @author Sezer Kılıç
 * @January 29,2025
 */



#include <stdio.h>
#include "stats.h"
int main(){
	unsigned int array_length;
	printf("\nPlease enter the number of elements of the array(Please enter a number less than 100.) : ");
	scanf("%d",&array_length);
	getchar();
	if(array_length == 0){
		printf("invalid number");
		return 1;
	}
	else if(array_length > 100){
		printf("Please enter string length less than 100.");
                return 1;
	}
	unsigned char my_array[100]={0};
	for(int i=0;i<array_length;i++){
		printf("\nPlease enter %d element of the array(0-255) : ",i);
		scanf("%hhu",&my_array[i]);
	}
	float median,mean;
	unsigned char maximum_element,minimum_element;
	printf("\n");
	print_array(my_array,array_length);
	
	mean = find_mean(my_array,array_length);
	maximum_element = find_maximum(my_array,array_length);
	minimum_element = find_minimum(my_array,array_length);
        
	sort_array(my_array,array_length);
	median = find_median(my_array,array_length);
        print_statics(median,mean,maximum_element,minimum_element);
	printf("\n");




	return 0;
}
void print_array(unsigned char my_array[], unsigned int array_length){
	printf("\nEntered Array : ");
        for(int i=0;i<array_length;i++){
	    printf("%i ",my_array[i]);
        }
}
void print_statics(float median,float mean,unsigned char maximum_element,unsigned char minimum_element){

	printf("\nmedian : %.2f",median);
	printf("\nmean : %.2f",mean);
	printf("\nmaximum element : %d",maximum_element);
	printf("\nminimum_element : %d",minimum_element);
}

float find_median(unsigned char my_array[], unsigned int array_length){
	unsigned int median_index;
        float  median;
	if(array_length % 2 == 1){
		median_index = ((array_length-1)/2) + 1;
		median = my_array[median_index-1];
	}else {
		median_index = array_length/2;
		median =(float)(my_array[median_index] + my_array[median_index-1])/2.0; 
	}
	return median;
}		
float find_mean(unsigned char my_array[],unsigned int array_length){
	float mean;
	unsigned int sum=0;
	for(int i=0;i<array_length;i++){
		sum += my_array[i];
	}
	mean = (float)(sum)/(float)(array_length);
	return mean;
}
unsigned char find_maximum(unsigned char my_array[],unsigned int array_length){
	unsigned char  maximum = my_array[0];
	for(int i=1;i<array_length;i++){
		if(my_array[i] > maximum){
			maximum = my_array[i];
		}
	}
	return maximum;
}

unsigned char find_minimum(unsigned char my_array[],unsigned int array_length){
	unsigned char minimum = my_array[0];
	for(int i=1;i<array_length;i++){
		if(my_array[i] < minimum){
			minimum = my_array[i];
		}
	}
	return minimum;
}
void sort_array(unsigned char my_array[],unsigned int array_length){
        unsigned char buffer;
	
	for(int i=0;i<array_length;i++){
		for(int j=0;j<array_length;j++){
			if(my_array[j+1]>my_array[j]){
				buffer = my_array[j];
				my_array[j]=my_array[j+1];
				my_array[j+1] = buffer;
			}
		}
	}
	printf("\nSorted array : " );
	for(int i=0;i<array_length;i++){
		printf("%d ",my_array[i]);
	}
}

