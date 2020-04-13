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
	total_weight = sum of matrix elements (for each operator)
Outputs:
	sobel = horizontal and vertical sobel operator matrices
		type: struct sobel_operators
*/
struct sobel_operators init_sobel(void);



#endif /* estimate_grad_h */
