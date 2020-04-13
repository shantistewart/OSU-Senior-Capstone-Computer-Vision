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
	x = vector coordinate 1
	y = vector coordinate 2
Outputs:
	norm = approximate L2 norm of input vector
*/
float approx_norm(float x, float y);


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
