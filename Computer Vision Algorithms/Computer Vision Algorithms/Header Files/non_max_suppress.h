//
//  non_max_suppress.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/24/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef non_max_suppress_h
#define non_max_suppress_h


#include "structs_and_constants.h"



/*
Function Description: performs horizontal non-maximal suppression on gradient image.
Inputs:
	grads = gradient image
		type: struct image
	suppress_length = (half) horizontal "suppression" length
Outputs:
	suppress_grads = non-maximally suppressed gradient image
		type: struct image
*/
struct image non_max_suppress(struct image grads, int suppress_length);



#endif /* non_max_suppress_h */
