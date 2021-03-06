//
//  blur_filter_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/4/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "blur_filter.h"



/*
int main() {
	// --------------------TESTING gaussian_2D_kernel() FUNCTION--------------------
	printf("\n----------TESTING gaussian_2D_kernel() FUNCTION----------\n\n");
	
	// test standard deviation of Gaussian kernel:
	float sigma = 1.0;
	
	// call function:
	struct gaussian_kernel g_kernel = gaussian_2D_kernel(sigma);
	
	// rolling sum of weights (to check normalization):
	float weight_sum = 0.0;
	printf("Gaussian kernel of size %dx%d with a standard deviation of %f:\n\n", KERNEL_SIZE, KERNEL_SIZE, sigma);
	for (int i=0; i<KERNEL_SIZE; i++) {
		for (int j=0; j<KERNEL_SIZE; j++) {
			printf("%f  ", g_kernel.kernel_matrix[i][j]);
			weight_sum +=  g_kernel.kernel_matrix[i][j];
		}
		printf("\n");
	}
	printf("\nSum of weights: %f\n\n\n", weight_sum);
 
 
 
	// --------------------TESTING blur_filter() FUNCTION--------------------
	printf("\n----------TESTING blur_filter() FUNCTION----------\n\n");
	
	// test input image:
	struct RGB_image raw_pic;
	// fill input image array and display:
	printf("Input image array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				raw_pic.pixels[color][i][j] = (color+1)*(i*NUM_COLS + j + 1);
				printf("%f  ", raw_pic.pixels[color][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	// call function:
	struct RGB_image blur_pic = blur_filter(raw_pic, sigma);
	
	// display blurred image array:
	printf("\nBlurred image array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				printf("%f  ", blur_pic.pixels[color][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	return 0;
}
*/
