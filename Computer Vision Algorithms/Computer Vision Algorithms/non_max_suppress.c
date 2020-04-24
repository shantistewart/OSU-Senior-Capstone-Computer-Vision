//
//  non_max_suppress.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/24/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "non_max_suppress.h"
#include <stdio.h>
#include "utility_functions.h"



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
struct image non_max_suppress(struct image grads, int suppress_length) {
	// non-maximally suppressed gradient image:
	struct image suppress_grads;
	// full suppression range subarray (size: 2*suppress_length+1)
	float full_suppress_subarray[2*suppress_length+1];
	// half suppression range subarray (size: suppress_length+1)
	float half_suppress_subarray[suppress_length+1];
	
	// perform horizontal non-maximal suppression:
	for (int i=0; i<NUM_ROWS; i++) {
		// middle part:
		for (int j=suppress_length; j<=NUM_COLS-1-suppress_length; j++) {
			// extract full suppression subarray from grads:
			for (int k=j-suppress_length; k<=j+suppress_length; k++) {
				full_suppress_subarray[k-(j-suppress_length)] = grads.pixels[i][k];
			}
			
			// if gradient value is not local max in suppression range, set to zero:
			if (grads.pixels[i][j] != maximum(2*suppress_length+1, full_suppress_subarray)) {
				suppress_grads.pixels[i][j] = 0.0;
			}
			// else keep value:
			else {
				suppress_grads.pixels[i][j] = grads.pixels[i][j];
			}
		}
		
		// left border:
		for (int j=0; j<=suppress_length-1; j++) {
			// extract (right-facing) half suppression subarray from grads:
			for (int k=j; k<=j+suppress_length; k++) {
				half_suppress_subarray[k-j] = grads.pixels[i][k];
			}
			
			// if gradient value is not local max in half suppression range, set to zero:
			if (grads.pixels[i][j] != maximum(suppress_length+1, half_suppress_subarray)) {
				suppress_grads.pixels[i][j] = 0.0;
			}
			// else keep value:
			else {
				suppress_grads.pixels[i][j] = grads.pixels[i][j];
			}
		}
		
		// right border:
		for (int j=NUM_COLS-suppress_length; j<NUM_COLS; j++) {
			// extract (left-facing) half suppression subarray from grads:
			for (int k=j-suppress_length; k<=j; k++) {
				half_suppress_subarray[k-(j-suppress_length)] = grads.pixels[i][k];
			}
			
			// if gradient value is not local max in half suppression range, set to zero:
			if (grads.pixels[i][j] != maximum(suppress_length+1, half_suppress_subarray)) {
				suppress_grads.pixels[i][j] = 0.0;
			}
			// else keep value:
			else {
				suppress_grads.pixels[i][j] = grads.pixels[i][j];
			}
		}
	}
	
	return suppress_grads;
}
