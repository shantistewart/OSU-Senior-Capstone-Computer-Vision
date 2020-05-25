//
//  utility_functions_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "utility_functions.h"



/*
int main() {
	// --------------------TESTING L1_norm_float() and L1_norm_int() FUNCTIONS--------------------
	printf("\n----------TESTING L1_norm_float() and L1_norm_int() FUNCTIONS----------\n\n");
	
	// test values:
	float x1_float = 2.5;
	float x2_float = -3.2;
	int x1_int = -7;
	int x2_int = -9;
	
	// call functions:
	float norm_float = L1_norm_float(x1_float, x2_float);
	int norm_int = L1_norm_int(x1_int, x2_int);
	
	// display L1 norms:
	printf("L1-norm of vector [%f, %f]: %f\n", x1_float, x2_float, norm_float);
	printf("L1-norm of vector [%d, %d]: %d\n\n\n", x1_int, x2_int, norm_int);
	
	
	
	// --------------------TESTING maximum() FUNCTION--------------------
	printf("\n----------TESTING maximum() FUNCTION----------\n\n");
	
	// test array:
	int size = 10;
	float array_1D[size];
	
	// fill and display array:
	printf("Array:\n");
	for (int i=0; i<size; i++) {
		array_1D[i] = 2.5*(i+1);
		printf("%f  ", array_1D[i]);
	}
	
	// call function:
	float max = maximum(size, array_1D);
	
	// display max value:
	printf("\nMax of array: %f\n\n\n", max);
	
	
	
	// --------------------TESTING arg_maximum() FUNCTION--------------------
	printf("\n----------TESTING arg_maximum() FUNCTION----------\n\n");
	
	// test array:
	int M = 5;
	int N = 8;
	float array_2D[M][N];
	// test mod number:
	int mod = 5;
	
	// fill and display array:
	printf("Array:\n");
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			array_2D[i][j] = (i*N + j + 1) % (i+4) + 0.5;
			printf("%f  ", array_2D[i][j]);
		}
		printf("\n");
	}
	
	// call function:
	struct arg_max max_elem = arg_maximum(M, N, array_2D);
	
	// display max value and argmax:
	printf("\nMax element of array: %f at (%d, %d)\n\n\n", max_elem.max, max_elem.coord.row, max_elem.coord.col);
	
	
	
	// --------------------TESTING conv_sum_2D() FUNCTION--------------------
	printf("\n----------TESTING conv_sum_2D() FUNCTION----------\n\n");
	
	// test arrays:
	M = 2;
	N = 2;
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
	
	// display convolution sum:
	printf("\nConvolution sum of array1 and array2: %f\n\n\n", conv_sum);
	
	
	
	// --------------------TESTING kernel_conv_2D() FUNCTION--------------------
	printf("\n----------TESTING kernel_conv_2D() FUNCTION----------\n\n");
	
	// test input array:
	struct RGB_image array;
	// fill input array and display:
	printf("Input array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				array.pixels[color][i][j] = (color+1)*(i*NUM_COLS + j + 1);
				printf("%f  ", array.pixels[color][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	// test kernel:
	N = 3;
	float kernel[N][N];
	// fill kernel and display:
	printf("\nKernel:\n\n");
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			kernel[i][j] = 1.0 / (N*N);
			printf("%f  ", kernel[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// call function:
	struct RGB_image conv_pic = kernel_conv_2D(array, N, kernel);
	
	// display convolution output array:
	printf("\nConvolution output array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				printf("%f  ", conv_pic.pixels[color][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
 
 
	printf("\n\n");
	return 0;
}
*/
