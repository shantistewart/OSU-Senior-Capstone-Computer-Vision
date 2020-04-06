//
//  utility_functions.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "utility_functions.h"
#include <stdio.h>


/*
Function Description: calculate the convolution sum of 2 2D arrays evaluated when the arrays are lined up.
Inputs:
	M = number of rows of arrays
	N = number of columns of arrays
	array1 = 1st array
		size: (M, N)
	array2 = 2nd array
		size: (M, N)
Outputs:
	conv_sum = convolution sum of array1 and array2
*/
float conv_sum_2D(int M, int N, float array1[M][N], float array2[M][N]) {
	// rolling sum:
	float conv_sum = 0.0;
	
	// calculate 2D convolution sum of array1 and array2:
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			conv_sum += array1[i][j] * array2[i][j];
		}
	}
	
	return conv_sum;
}


/*
Function Description: performs 2D kernel same (zero-padded) convolution on an input array, using a kernel matrix.
Inputs:
	array = input array
		size: (NUM_ROWS, NUM_COLS)
	N = size of kernel matrix
	kernel = kernel matrix
		size: (N, N)
Outputs:
	conv = 2D kernel convolution output
		type: struct image
*/
struct image kernel_conv_2D(float array[NUM_ROWS][NUM_COLS], int N, float kernel[N][N]) {
	// padding size for same convolution:
	int pad = (N-1) / 2;
	// array for zero-padded input array:
	float pad_array[NUM_ROWS+2*pad][NUM_COLS+2*pad];
	
	// zero-pad input array:
	for (int i=0; i<NUM_ROWS+2*pad; i++) {
		for (int j=0; j<NUM_COLS+2*pad; j++) {
			// if in padded borders:
			if ( i<pad || j<pad || i>NUM_ROWS-1+pad || j>NUM_COLS-1+pad ) {
				// pad with zero:
				pad_array[i][j] = 0;
			}
			else {
				// copy value from un-padded array:
				pad_array[i][j] = array[i-pad][j-pad];
			}
		}
	}
	/*
	// display padded image values:
	printf("\nPadded input array:\n");
	for (int i=0; i<NUM_ROWS+2*pad; i++) {
		for (int j=0; j<NUM_COLS+2*pad; j++) {
			printf("%f  ", pad_array[i][j]);
		}
		printf("\n");
	}
	*/
	
	// 2D convolution output image struct:
	struct image conv_pic;
	// subarray of size (N,N) of padded_pic to use as input to conv_sum_2D():
	float subarray[N][N];
	
	// same-convolve image with kernel:
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			// extract subarray from padded_pic:
			for (int k=0; k<N; k++) {
				for (int l=0; l<N; l++) {
					subarray[k][l] = pad_array[i+k][j+l];
				}
			}
			conv_pic.pixels[i][j] = conv_sum_2D(N, N, subarray, kernel);
		}
	}
	
	return conv_pic;
}
