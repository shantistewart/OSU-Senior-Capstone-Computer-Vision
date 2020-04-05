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
	
	// perform a 2D convolution sum of array1 and array2:
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			conv_sum += array1[i][j] * array2[i][j];
		}
	}
	
	return conv_sum;
}
