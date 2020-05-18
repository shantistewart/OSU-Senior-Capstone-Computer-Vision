//
//  estimate_grad.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/12/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "estimate_grad.h"
#include <stdio.h>
#include "utility_functions.h"



/*
Function Description: initializes horizontal and vertical Sobel operators.
Inputs:
	norm = "Boolean" to select whether to normalize Sobel operator values
		if norm == 1: normalize values; else: don't normalize values
Outputs:
	sobel = horizontal and vertical sobel operator matrices
		type: struct sobel_operators
*/
struct sobel_operators init_sobel(int norm) {
	// sobel_operators struct instance:
	struct sobel_operators sobel;
	// middle index:
	int middle = SOBEL_SIZE / 2;
	// running sum of weights:
	float total_weight = 0.0;
	
	// initialize horizontal sobel operator:
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			// if middle column:
			if (j == middle) {
				sobel.sobel_horiz[i][j] = 0.0;
			}
			// else if middle row:
			else if (i == middle) {
				// if left half:
				if (j < middle) {
					sobel.sobel_horiz[i][j] = -2.0;
				}
				// else right half:
				else {
					sobel.sobel_horiz[i][j] = 2.0;
				}
			}
			// else if left half:
			else if (j < middle) {
				sobel.sobel_horiz[i][j] = -1.0;
			}
			// else right half:
			else {
				sobel.sobel_horiz[i][j] = 1.0;
			}
			// update total weight:
			if (sobel.sobel_horiz[i][j] < 0.0) {
				total_weight += -1*sobel.sobel_horiz[i][j];
			}
			else {
				total_weight += sobel.sobel_horiz[i][j];
			}
		}
	}
	
	// initialize vertical sobel operator:
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			// if middle row:
			if (i == middle) {
				sobel.sobel_vert[i][j] = 0.0;
			}
			// else if middle column:
			else if (j == middle) {
				// if bottom half:
				if (i > middle) {
					sobel.sobel_vert[i][j] = -2.0;
				}
				// else upper half:
				else {
					sobel.sobel_vert[i][j] = 2.0;
				}
			}
			// else if bottom half:
			else if (i > middle) {
				sobel.sobel_vert[i][j] = -1.0;
			}
			// else upper half:
			else {
				sobel.sobel_vert[i][j] = 1.0;
			}
		}
	}
	
	// normalize values:
	if (norm==1) {
		for (int i=0; i<SOBEL_SIZE; i++) {
			for (int j=0; j<SOBEL_SIZE; j++) {
				sobel.sobel_horiz[i][j] /= total_weight;
				sobel.sobel_vert[i][j] /= total_weight;
			}
		}
	}
	
	return sobel;
}


/*
Function Description: estimates gradients of input image using kernel convolution with Sobel operators.
Inputs:
	pic = RGB image
		type: struct RGB_image
	norm = "Boolean" to select whether to normalize Sobel operator values
		if norm == 1: normalize values; else: don't normalize values
Outputs:
	grads = estimated gradients of input image
		type: struct image
*/
struct image estimate_grad(struct RGB_image pic, int norm) {
	// get Sobel operators:
	struct sobel_operators sobel = init_sobel(norm);
	// padding size for same convolution:
	int pad = (SOBEL_SIZE-1) / 2;
	// estimated gradients struct:
	struct image grads;
	
	// subarray of size (SOBEL_SIZE, SOBEL_SIZE) of pic to use as input to conv_sum_2D():
	float subarray[SOBEL_SIZE][SOBEL_SIZE];
	// array to hold normalized gradient values for all color channels at each pixel:
	float grad_norm[NUM_COLORS];
	// gradient values:
	float grad_horiz;
	float grad_vert;
	
	// convolve each channel of input array with horizontal and vertical Sobel operator:
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			// if kernel matrix doesn't fit entirely in input image:
			if ( i<pad || j<pad || i>NUM_ROWS-1-pad || j>NUM_COLS-1-pad ) {
				// pad with zero:
				grads.pixels[i][j] = 0.0;
			}
			// else estimate gradient:
			else {
				for (int color=0; color<NUM_COLORS; color++) {
					// extract subarray from pic:
					for (int k=i-pad; k<=i+pad; k++) {
						for (int l=j-pad; l<=j+pad; l++) {
							subarray[k-(i-pad)][l-(j-pad)] = pic.pixels[color][k][l];
						}
					}
					// estimate horizontal gradient:
					grad_horiz = conv_sum_2D(SOBEL_SIZE, SOBEL_SIZE, subarray, sobel.sobel_horiz);
					// estimate vertical gradient:
					grad_vert = conv_sum_2D(SOBEL_SIZE, SOBEL_SIZE, subarray, sobel.sobel_vert);
					// calculate L1-norm of horizontal and vertical gradients:
					grad_norm[color] = L1_norm_float(grad_horiz, grad_vert);
				}
				// take max gradient value over all color channels:
				grads.pixels[i][j] = maximum(NUM_COLORS, grad_norm);
			}
		}
	}
	
	return grads;
}
