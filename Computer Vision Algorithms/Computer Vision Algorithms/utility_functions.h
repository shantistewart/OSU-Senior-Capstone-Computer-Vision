//
//  utility_functions.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef utility_functions_h
#define utility_functions_h


#include "structs_and_constants.h"



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
float conv_sum_2D(int M, int N, float array1[M][N], float array2[M][N]);


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
struct image kernel_conv_2D(float array[NUM_ROWS][NUM_COLS], int N, float kernel[N][N]);



#endif /* utility_functions_h */
