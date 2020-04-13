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
	
	/*
	// convolve each channel of input array with horizontal Sobel operator:
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
	*/
	
	// convolve each channel of input array with vertical Sobel operator:
	
	return grads;
}
