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
Function Description: performs 2D kernel same (zero-padded) convolution on an input image, using a kernel matrix.
Inputs:
	pic = input image
		type: struct image
	N = size of kernel matrix (must be odd!)
	kernel = kernel matrix
		size: (N, N)
Outputs:
	conv = 2D kernel convolution output
		type: struct image
*/
struct image kernel_conv_2D(struct image pic, int N, float kernel[N][N]) {
	// padding size for same convolution:
	int pad = (N-1) / 2;
	// zero-pad input image:
	float padded_pic[NUM_ROWS+2*pad][NUM_COLS+2*pad];
	for (int i=0; i<NUM_ROWS+2*pad; i++) {
		for (int j=0; j<NUM_COLS+2*pad; j++) {
			// if in padded borders:
			if ( i<pad || j<pad || i>NUM_ROWS-1+pad || j>NUM_COLS-1+pad ) {
				// pad with zero:
				padded_pic[i][j] = 0;
			}
			else {
				// copy value from un-padded image:
				padded_pic[i][j] = pic.pixels[i-pad][j-pad];
			}
		}
	}
	// display padded image values:
	printf("\nPadded input array:\n");
	for (int i=0; i<NUM_ROWS+2*pad; i++) {
		for (int j=0; j<NUM_COLS+2*pad; j++) {
			printf("%f  ", padded_pic[i][j]);
		}
		printf("\n");
	}
	
	// 2D convolution output image:
	struct image conv_pic;
	
	// ...
	
	return conv_pic;
}
