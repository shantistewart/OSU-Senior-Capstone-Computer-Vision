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
#include "utility_functions.h"



/*
Function Description: approximates a 2D (symmetrical) Gaussian kernel matrix.
Inputs:
	sigma = standard deviation of Gaussian
Outputs:
	kernel = Gaussian kernel matrix
		size: (KERNEL_SIZE, KERNEL_SIZE)
2D Gaussian distribution:
	f(x, y) = (1 / (pi*alpha)) * e^(-(x^2 + y^2) / alpha)
		where alpha = 2*sigma^2
*/
struct kernel gaussian_2D_kernel(float sigma) {
	// kernel struct instance:
	struct kernel gaussian_kernel;
	// half-size of kernel:
	int half_size = KERNEL_SIZE / 2;
	// "alpha" value:
	float alpha = 2*sigma*sigma;
	// rolling sum of weights:
	float weight_sum = 0.0;
	
    // fill kernel with Gaussian values:
	for (int x = -half_size; x <= half_size; x++) {
		for (int y = -half_size; y <= half_size; y++) {
			gaussian_kernel.kernel_matrix[x+half_size][y+half_size] = (1 / (M_PI*alpha)) * exp(-(x*x + y*y) / alpha);
			weight_sum += gaussian_kernel.kernel_matrix[x+half_size][y+half_size];
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


/*
Function Description: convolves image with a blurring filter to reduce noise.
Inputs:
	raw_pic = raw RGB image
		type: struct RGB_image
	sigma = standard deviation of Gaussian kernel
Outputs:
	blur_pic = blurred image
		type: struct RGB_image
*/
struct RGB_image blur_filter(struct RGB_image raw_pic, float sigma) {
	// calculate Gaussian kernel:
	struct kernel G_kernel = gaussian_2D_kernel(sigma);
	// blurred image struct:
	struct RGB_image blur_pic;
	
	// convolve raw image with Gaussian kernel to reduce noise (blur image):
	for (int color=0; color<NUM_COLORS; color++) {
		// blur_pic.pixels[color] = 
	}
	
	return blur_pic;
}
