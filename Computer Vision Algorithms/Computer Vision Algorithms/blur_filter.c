//
//  blur_filter.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/4/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "blur_filter.h"
#include <stdio.h>
#include <math.h>



/*
Function Description: approximates a 2D (symmetrical) Gaussian kernel matrix.
Inputs:
	sigma = standard deviation of Gaussian
Outputs:
	kernel = Gaussian kernel matrix
		size: [KERNEL_SIZE, KERNEL_SIZE]
2D Gaussian distribution:
	f(x, y) = (1 / (pi*alpha)) * e^(-(x^2 + y^2) / alpha)
		where alpha = 2*sigma^2
*/
struct kernel gaussian_2D_kernel(float sigma) {
	// kernel struct instance:
	struct kernel gaussian_kernel;
	// half-width of kernel:
	int half_width = KERNEL_SIZE / 2;
	// "alpha" value:
	float alpha = 2*sigma*sigma;
	// rolling sum of weights:
	float weight_sum = 0.0;
	
    // fill kernel with Gaussian values:
	for (int x = -half_width; x <= half_width; x++) {
		for (int y = -half_width; y <= half_width; y++) {
			gaussian_kernel.kernel_matrix[x+half_width][y+half_width] = (1 / (M_PI*alpha)) * exp(-(x*x + y*y) / alpha);
			weight_sum += gaussian_kernel.kernel_matrix[x+half_width][y+half_width];
		}
	}
	// normalize values:
	for (int i=0; i<KERNEL_SIZE; i++) {
		for (int j=0; j<KERNEL_SIZE; j++) {
			gaussian_kernel.kernel_matrix[i][j] /= weight_sum;
		}
	}
	
	return gaussian_kernel;
}
