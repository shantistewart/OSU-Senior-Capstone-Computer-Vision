//
//  estimate_grad_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/12/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "estimate_grad.h"



/*
int main() {
	// --------------------TESTING init_sobel() FUNCTION--------------------
	printf("\n----------TESTING init_sobel() FUNCTION----------\n\n");
	
	// test normalization:
	float norm = 8.0;
	// call function:
	struct sobel_operators sobel = init_sobel(norm);
	
	printf("Horizontal Sobel operator of size %dx%d:\n", SOBEL_SIZE, SOBEL_SIZE);
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			printf("%f  ", sobel.sobel_horiz[i][j]);
		}
		printf("\n");
	}
	
	printf("\nVertical Sobel operator of size %dx%d:\n", SOBEL_SIZE, SOBEL_SIZE);
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			printf("%f  ", sobel.sobel_vert[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	return 0;
}
*/
