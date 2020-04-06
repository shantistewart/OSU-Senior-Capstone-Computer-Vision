//
//  utility_functions.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef utility_functions_h
#define utility_functions_h

#include <stdio.h>


// number of rows of image pixels:
#define NUM_ROWS 2
// number of columns of image pixels:
#define NUM_COLS 3

struct image {
	float pixels[NUM_ROWS][NUM_COLS];
};



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



#endif /* utility_functions_h */
