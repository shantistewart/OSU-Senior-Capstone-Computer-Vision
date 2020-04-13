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
	norm = number to divide default Sobel operator values by
Outputs:
	sobel = horizontal and vertical sobel operator matrices
		type: struct sobel_operators
*/
struct sobel_operators init_sobel(float norm) {
	// sobel_operators struct instance:
	struct sobel_operators sobel;
	// middle index:
	int middle = SOBEL_SIZE / 2;
	
	// initialize horizontal sobel operator:
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			// if middle column:
			if (j == middle) {
				sobel.sobel_horiz[i][j] = 0.0 / norm;
			}
			// else if middle row:
			else if (i == middle) {
				// if left half:
				if (j < middle) {
					sobel.sobel_horiz[i][j] = -2.0 / norm;
				}
				// else right half:
				else {
					sobel.sobel_horiz[i][j] = 2.0 / norm;
				}
			}
			// else if left half:
			else if (j < middle) {
				sobel.sobel_horiz[i][j] = -1.0 / norm;
			}
			// else right half:
			else {
				sobel.sobel_horiz[i][j] = 1.0 / norm;
			}
		}
	}
	
	// initialize vertical sobel operator:
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			// if middle row:
			if (i == middle) {
				sobel.sobel_vert[i][j] = 0.0 / norm;
			}
			// else if middle column:
			else if (j == middle) {
				// if bottom half:
				if (i > middle) {
					sobel.sobel_vert[i][j] = -2.0 / norm;
				}
				// else upper half:
				else {
					sobel.sobel_vert[i][j] = 2.0 / norm;
				}
			}
			// else if bottom half:
			else if (i > middle) {
				sobel.sobel_vert[i][j] = -1.0 / norm;
			}
			// else upper half:
			else {
				sobel.sobel_vert[i][j] = 1.0 / norm;
			}
		}
	}
	
	return sobel;
}


/*
Function Description: estimates gradients of input image using same (post-zero-padded) kernel convolution with Sobel operators.
Inputs:
	pic = RGB image
		type: struct RGB_image
	norm = number to divide default Sobel operator values by
Outputs:
	grads = estimated gradients of input image
		type: struct image
*/
struct image estimate_grad(struct RGB_image pic, float norm) {
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
	// max gradient value over all color channels:
	float grad_max = 0.0;
	
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
					for (int k=i-pad; i<=i+pad; k++) {
						for (int l=j-pad; l<=j+pad; l++) {
							subarray[k-(i-pad)][l-(j-pad)] = pic.pixels[color][k][l];
						}
					}
					// estimate horizontal gradient:
					grad_horiz = conv_sum_2D(SOBEL_SIZE, SOBEL_SIZE, subarray, sobel.sobel_horiz);
					// estimate vertical gradient:
					grad_vert = conv_sum_2D(SOBEL_SIZE, SOBEL_SIZE, subarray, sobel.sobel_vert);
					// approximate L2 norm of horizontal and vertical gradients:
					grad_norm[color] = approx_norm(grad_horiz, grad_vert);
				}
				// take max gradient value over all color channels:
				for (int color=0; color<NUM_COLORS; color++) {
					if (grad_norm[color] > grad_max) {
						grad_max = grad_norm[color];
					}
				}
				// store max gradient value:
				grads.pixels[i][j] = grad_max;
				// reset max gradient for next iteration:
				grad_max = 0.0;
			}
		}
	}
	
	return grads;
}
