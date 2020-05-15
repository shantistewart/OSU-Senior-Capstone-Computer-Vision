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
Function Description: calculates the L1-norm of a 2D vector.
Inputs:
	x1 = vector coordinate 1
	x2 = vector coordinate 2
Outputs: L1-norm of input vector
L1-norm: ||x|| = |x1| + |x2|
*/
float L1_norm(float x1, float x2) {
	// make values positive if not already:
	if (x1 < 0) {
		x1 = -1 * x1;
	}
	if (x2 < 0) {
		x2 = -1 * x2;
	}
	
	return x1 + x2;
}


/*
Function Description: determines maximum element of a 1D array.
Inputs:
	size = size of input array
	array = input array
Outputs:
	max = maximum element of array
*/
float maximum(int size, float array[size]) {
	// rolling max:
	float max = array[0];
	
	for (int i=0; i<size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	
	return max;
}


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
struct arg_max arg_maximum(int M, int N, float array[M][N]) {
	// struct to hold max value and its coordinates:
	struct arg_max max_elem;
	max_elem.max = array[0][0];
	max_elem.coord.row = 0;
	max_elem.coord.col = 0;
	
	for (int i=0; i<M; i++) {
		for (int j=0; j<N; j++) {
			if (array[i][j] > max_elem.max) {
				max_elem.max = array[i][j];
				max_elem.coord.row = i;
				max_elem.coord.col = j;
			}
		}
	}
	
	return max_elem;
}


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
struct RGB_image kernel_conv_2D(struct RGB_image pic, int N, float kernel[N][N]) {
	// padding size for same convolution:
	int pad = (N-1) / 2;
	// zero-padded input array:
	float pad_array[NUM_COLORS][NUM_ROWS+2*pad][NUM_COLS+2*pad];
	
	// zero-pad input array:
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS+2*pad; i++) {
			for (int j=0; j<NUM_COLS+2*pad; j++) {
				// if in padded borders:
				if ( i<pad || j<pad || i>NUM_ROWS-1+pad || j>NUM_COLS-1+pad ) {
					// pad with zero:
					pad_array[color][i][j] = 0.0;
				}
				else {
					// copy value from un-padded array:
					pad_array[color][i][j] = pic.pixels[color][i-pad][j-pad];
				}
			}
		}
	}
	/*
	// display padded input array:
	printf("\nPadded input array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS+2*pad; i++) {
			for (int j=0; j<NUM_COLS+2*pad; j++) {
				printf("%f  ", pad_array[color][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/
	
	// 2D convolution output RGB_image struct:
	struct RGB_image conv_pic;
	// subarray of size (N,N) of padded_pic to use as input to conv_sum_2D():
	float subarray[N][N];
	
	// convolve each channel of padded input array with kernel:
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				// extract subarray from padded_pic:
				for (int k=0; k<N; k++) {
					for (int l=0; l<N; l++) {
						subarray[k][l] = pad_array[color][i+k][j+l];
					}
				}
				conv_pic.pixels[color][i][j] = conv_sum_2D(N, N, subarray, kernel);
			}
		}
	}
	
	return conv_pic;
}
