//
//  blur_filter_test.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/4/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "blur_filter.h"



int main() {
	printf("\n----------TESTING gaussian_2D_kernel() FUNCTION----------\n\n");
	float sigma = 1.0;
	struct kernel G_kernel = gaussian_2D_kernel(sigma);
	
	printf("Gaussian kernel of size %dx%d with a standard deviation of %f:\n\n", KERNEL_SIZE, KERNEL_SIZE, sigma);
	for (int i=0; i<KERNEL_SIZE; i++) {
		printf("Row %d:  ", i+1);
		for (int j=0; j<KERNEL_SIZE; j++) {
			printf("%f  ", G_kernel.kernel_matrix[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	return 0;
}
