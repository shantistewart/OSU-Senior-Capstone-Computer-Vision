//
//  utility_functions_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "utility_functions.h"



int main() {
	printf("\n----------TESTING conv_sum_2D() FUNCTION----------\n\n");
	
	// test arrays:
	int M = 2;
	int N = 3;
	float array1[M][N];
	float array2[M][N];
	
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			array1[i][j] = i*N + j + 1;
			array2[i][j] = 2 * (i*N + j + 1);
		}
	}
	printf("Array 1:\n");
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			printf("%f  ", array1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Array 2:\n");
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			printf("%f  ", array2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// call function:
	float conv_sum = conv_sum_2D(M, N, array1, array2);
	printf("Convolution sum of array1 and array2 is: %f\n", conv_sum);
	
	printf("\n\n");
	return 0;
}
