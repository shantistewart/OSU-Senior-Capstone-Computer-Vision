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
		type: struct gaussian_kernel
2D Gaussian distribution:
	f(x, y) = (1 / (pi*alpha)) * e^(-(x^2 + y^2) / alpha)
		where alpha = 2*sigma^2
*/
struct gaussian_kernel gaussian_2D_kernel(float sigma) {
	// kernel struct instance:
	struct gaussian_kernel g_kernel;
	// half-size of kernel:
	int half_size = KERNEL_SIZE / 2;
	// "alpha" value:
	float alpha = 2*sigma*sigma;
	// rolling sum of weights:
	float weight_sum = 0.0;
	
    // fill kernel with Gaussian values:
	for (int x = -half_size; x <= half_size; x++) {
		for (int y = -half_size; y <= half_size; y++) {
			g_kernel.kernel_matrix[x+half_size][y+half_size] = (1 / (M_PI*alpha)) * exp(-(x*x + y*y) / alpha);
			weight_sum += g_kernel.kernel_matrix[x+half_size][y+half_size];
		}
	}
	// normalize values:
	for (int i=0; i<KERNEL_SIZE; i++) {
		for (int j=0; j<KERNEL_SIZE; j++) {
			g_kernel.kernel_matrix[i][j] /= weight_sum;
		}
	}
	
	return g_kernel;
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
	struct gaussian_kernel g_kernel = gaussian_2D_kernel(sigma);
	// blurred image struct:
	struct RGB_image blur_pic;
	// image struct for color subarrays of raw image:
	struct image raw_pic_subarray;
	
	// convolve raw image with Gaussian kernel to reduce noise (blur image):
	for (int k=0; k<NUM_COLORS; k++) {
		// blur color channel k of raw image:
		raw_pic_subarray = kernel_conv_2D(raw_pic.pixels[k], KERNEL_SIZE, g_kernel.kernel_matrix);
		// copy blurred image values of color channel k:
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				blur_pic.pixels[k][i][j] = raw_pic_subarray.pixels[i][j];
			}
		}
	}
	
	return blur_pic;
}
