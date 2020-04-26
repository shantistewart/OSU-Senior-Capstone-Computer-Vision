//
//  estimate_grad.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/12/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef estimate_grad_h
#define estimate_grad_h


#include "structs_and_constants.h"



/*
Function Description: initializes horizontal and vertical Sobel operators.
Inputs:
	norm = "Boolean" to select whether to normalize Sobel operator values
		if norm == 1: normalize values; else: don't normalize values
Outputs:
	sobel = horizontal and vertical sobel operator matrices
		type: struct sobel_operators
*/
struct sobel_operators init_sobel(int norm);


/*
Function Description: estimates gradients of input image using kernel convolution with Sobel operators.
Inputs:
	pic = RGB image
		type: struct RGB_image
	norm = "Boolean" to select whether to normalize Sobel operator values
		if norm == 1: normalize values; else: don't normalize values
Outputs:
	grads = estimated gradients of input image
		type: struct image
*/
struct image estimate_grad(struct RGB_image pic, int norm);



#endif /* estimate_grad_h */
