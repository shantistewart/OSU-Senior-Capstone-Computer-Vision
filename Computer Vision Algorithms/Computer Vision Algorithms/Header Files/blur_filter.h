//
//  blur_filter.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/4/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef blur_filter_h
#define blur_filter_h


#include "structs_and_constants.h"



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
struct gaussian_kernel gaussian_2D_kernel(float sigma);


/*
Function Description: convolves input image with a Gaussian blur filter to reduce noise.
Inputs:
	raw_pic = raw RGB image
		type: struct RGB_image
	sigma = standard deviation of Gaussian kernel
Outputs:
	blur_pic = blurred image
		type: struct RGB_image
*/
struct RGB_image blur_filter(struct RGB_image raw_pic, float sigma);



#endif /* blur_filter_h */
