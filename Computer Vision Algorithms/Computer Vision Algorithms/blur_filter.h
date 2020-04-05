//
//  blur_filter.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/4/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef blur_filter_h
#define blur_filter_h


// size of Gaussian kernel:
#define KERNEL_SIZE 5

struct kernel {
	float kernel_matrix[KERNEL_SIZE][KERNEL_SIZE];
};



/*
Function Description: approximates a 2D (symmetrical) Gaussian kernel matrix.
Inputs:
	N = dimensions of Gaussian kernel matrix
		must be odd!
	sigma = standard deviation of Gaussian
Outputs:
	kernel = Gaussian kernel matrix
		size: [N, N]
2D Gaussian distribution:
	f(x, y) = (1 / (pi*alpha)) * e^(-(x^2 + y^2) / alpha)
		where alpha = 2*sigma^2
*/
struct kernel gaussian_2D_kernel(float sigma);



#endif /* blur_filter_h */
