//
//  estimate_grad_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/12/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "estimate_grad.h"



// /*
int main() {
	// --------------------TESTING init_sobel() FUNCTION--------------------
	printf("\n----------TESTING init_sobel() FUNCTION----------\n\n");
	
	// test normalization:
	int norm = 0;
	// running sum of weights:
	float total_weight = 0.0;
	
	// call function:
	struct sobel_operators sobel = init_sobel(norm);
	
	printf("Horizontal Sobel operator of size %dx%d:\n", SOBEL_SIZE, SOBEL_SIZE);
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			printf("%f  ", sobel.sobel_horiz[i][j]);
			// update total weight:
			if (sobel.sobel_horiz[i][j] < 0.0) {
				total_weight += -1*sobel.sobel_horiz[i][j];
			}
			else {
				total_weight += sobel.sobel_horiz[i][j];
			}
		}
		printf("\n");
	}
	// check that normalization is correct:
	if (total_weight < 1.000 || total_weight > 1.001) {
		printf("\nNot normalized: total weight = %f.\n", total_weight);
	}
	
	// reset normalization:
	total_weight = 0.0;
	printf("\nVertical Sobel operator of size %dx%d:\n", SOBEL_SIZE, SOBEL_SIZE);
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			printf("%f  ", sobel.sobel_vert[i][j]);
			// update total weight:
			if (sobel.sobel_horiz[i][j] < 0.0) {
				total_weight += -1*sobel.sobel_horiz[i][j];
			}
			else {
				total_weight += sobel.sobel_horiz[i][j];
			}
		}
		printf("\n");
	}
	// check that normalization is correct:
	if (total_weight < 1.000 || total_weight > 1.001) {
		printf("\nNot normalized: total weight = %f.\n", total_weight);
	}
	
	printf("\n\n");
	
	
	
	// --------------------TESTING estimate_grad() FUNCTION--------------------
	printf("\n----------TESTING estimate_grad() FUNCTION----------\n\n");
	
	// test normalization:
	norm = 0;
	// test input image:
	struct RGB_image pic;
	// fill input image array (for NUM_ROWS = 7 and NUM_COLS = 7):
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				if (j==2 && i!=0 && i!= NUM_ROWS-1) {
					pic.pixels[color][i][j] = color+1;
				}
				else if (j==4 && i!=0 && i!= NUM_ROWS-1) {
					pic.pixels[color][i][j] = 2*(color+1) + 1;
				}
				else {
					pic.pixels[color][i][j] = 0.0;
				}
			}
		}
	}
	// display input image:
	printf("Input image array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				printf("%d  ", (int)pic.pixels[color][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	// call function:
	struct image grads = estimate_grad(pic, norm);
	
	// display estimated gradients:
	printf("\nEstimated gradients array:\n\n");
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			printf("%d  ", (int)grads.pixels[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	return 0;
}
// */
