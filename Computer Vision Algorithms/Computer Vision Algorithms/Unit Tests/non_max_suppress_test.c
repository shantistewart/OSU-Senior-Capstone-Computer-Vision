//
//  non_max_suppress_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/24/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "non_max_suppress.h"



/*
int main() {
	// --------------------TESTING non_max_suppress() FUNCTION--------------------
	printf("\n----------TESTING non_max_suppress() FUNCTION----------\n\n");
	
	// test (half) suppression length:
	int suppress_length = 2;
	// test input gradient image:
	struct image grads;
	// test mod number:
	int mod = 5;
	
	// fill and display input gradient image array:
	printf("Input gradient image array:\n\n");
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			grads.pixels[i][j] = (i*NUM_COLS + j + 1) % mod;
			printf("%d  ", (int)grads.pixels[i][j]);
		}
		printf("\n");
	}
	
	// call function:
	struct image suppress_grads = non_max_suppress(grads, suppress_length);
	
	// display non-maximally suppressed gradient image array:
	printf("\nNon-maximally suppressed gradient image array:\n\n");
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			printf("%d  ", (int)suppress_grads.pixels[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	return 0;
}
*/
