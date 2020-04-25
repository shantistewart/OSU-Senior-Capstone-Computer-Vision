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
	
	// normalization:
	int norm = 1;
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
	
	// normalization:
	norm = 1;
	// test input image:
	struct RGB_image pic;
	// fill and display input image array (for NUM_ROWS = 7 and NUM_COLS = 7):
	printf("Input image array:\n\n");
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				if (j==2 && i!=0 && i!= NUM_ROWS-1) {
					pic.pixels[color][i][j] = -(NUM_COLORS - color+1);
				}
				else if (j==4 && i!=0 && i!= NUM_ROWS-1) {
					pic.pixels[color][i][j] = -(NUM_COLORS - 2*(color+1) + 1);
				}
				else {
					pic.pixels[color][i][j] = 0.0;
				}
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
			printf("%f  ", grads.pixels[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	return 0;
}
// */
