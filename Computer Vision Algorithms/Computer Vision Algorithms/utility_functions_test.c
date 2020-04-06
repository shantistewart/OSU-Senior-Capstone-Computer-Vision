//
//  utility_functions_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "utility_functions.h"



// /*
int main() {
	// --------------------TESTING conv_sum_2D() FUNCTION--------------------
	printf("\n----------TESTING conv_sum_2D() FUNCTION----------\n\n");
	
	// test arrays:
	int M = 2;
	int N = 2;
	float array1[M][N];
	float array2[M][N];
	
	// fill array1 and array2:
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			array1[i][j] = i*N + j + 1;
			array2[i][j] = 2 * (i*N + j + 1);
		}
	}
	// display array1:
	printf("Array 1:\n");
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			printf("%f  ", array1[i][j]);
		}
		printf("\n");
	}
	// display array2:
	printf("\nArray 2:\n");
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			printf("%f  ", array2[i][j]);
		}
		printf("\n");
	}
	
	// call function:
	float conv_sum = conv_sum_2D(M, N, array1, array2);
	printf("\nConvolution sum of array1 and array2: %f\n", conv_sum);
	printf("\n");
	
	
	// --------------------TESTING kernel_conv_2D() FUNCTION--------------------
	printf("\n----------TESTING kernel_conv_2D() FUNCTION----------\n\n");
	
	// test input array:
	struct image pic;
	// fill input array and display:
	printf("Input array:\n");
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			pic.pixels[i][j] = i*NUM_COLS + j + 1;
			printf("%f  ", pic.pixels[i][j]);
		}
		printf("\n");
	}
	
	// test kernel:
	N = 3;
	float kernel[N][N];
	// fill kernel and display:
	printf("\nKernel:\n");
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			kernel[i][j] = 1.0 / (N*N);
			printf("%f  ", kernel[i][j]);
		}
		printf("\n");
	}
	
	// call function:
	struct image conv_pic = kernel_conv_2D(pic, N, kernel);
	// display convolution output array:
	printf("\nConvolution output array:\n");
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			printf("%f  ", conv_pic.pixels[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	return 0;
}
// */
