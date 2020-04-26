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
Function Description: approximates a L2 norm of a 2D vector.
Inputs:
	x1 = vector coordinate 1
	x2 = vector coordinate 2
Outputs: approximate L2 norm of input vector
Approximation: ||x|| = |x1| + |x2|
*/
float approx_norm(float x1, float x2);


/*
Function Description: determines maximum element of a 1D array.
Inputs:
	size = size of input array
	array = input array
Outputs:
	max = maximum element of array
*/
float maximum(int size, float array[size]);


/*
Function Description: determines maximum element of a 2D array and its coordinates.
Inputs:
	M = number of rows of array
	N = number of columns of array
	array = input array
Outputs:
	max_elem = maximum value and its coordinates
		type: struct arg_max
*/
struct arg_max arg_maximum(int M, int N, float array[M][N]);


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
Function Description: performs 2D kernel same (zero-padded) convolution on a multi-channel 2D input array with a kernel matrix.
Inputs:
	pic = multi-channel 2D input array
		type: struct RGB_image
			size of pic.pixels: (NUM_COLORS, NUM_ROWS, NUM_COLS)
	N = size of kernel matrix
	kernel = kernel matrix
		size: (N, N)
Outputs:
	conv_pic = 2D kernel convolution output
		type: struct RGB_image
			size of conv_pic: ((NUM_COLORS, NUM_ROWS, NUM_COLS)
*/
struct RGB_image kernel_conv_2D(struct RGB_image pic, int N, float kernel[N][N]);



#endif /* utility_functions_h */
