//
//  estimate_grad.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/12/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "estimate_grad.h"
#include <stdio.h>



/*
Function Description: initializes horizontal and vertical Sobel operators.
Inputs:
	norm = number to divide default Sobel operator values by
Outputs:
	sobel = horizontal and vertical sobel operator matrices
		type: struct sobel_operators
*/
struct sobel_operators init_sobel(float norm) {
	// sobel_operators struct instance:
	struct sobel_operators sobel;
	// middle index:
	int middle = SOBEL_SIZE / 2;
	
	// initialize horizontal sobel operator:
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			// if middle column:
			if (j == middle) {
				sobel.sobel_horiz[i][j] = 0.0 / norm;
			}
			// else if middle row:
			else if (i == middle) {
				// if left half:
				if (j < middle) {
					sobel.sobel_horiz[i][j] = -2.0 / norm;
				}
				// else right half:
				else {
					sobel.sobel_horiz[i][j] = 2.0 / norm;
				}
			}
			// else if left half:
			else if (j < middle) {
				sobel.sobel_horiz[i][j] = -1.0 / norm;
			}
			// else right half:
			else {
				sobel.sobel_horiz[i][j] = 1.0 / norm;
			}
		}
	}
	
	// initialize vertical sobel operator:
	for (int i=0; i<SOBEL_SIZE; i++) {
		for (int j=0; j<SOBEL_SIZE; j++) {
			// if middle row:
			if (i == middle) {
				sobel.sobel_vert[i][j] = 0.0 / norm;
			}
			// else if middle column:
			else if (j == middle) {
				// if bottom half:
				if (i > middle) {
					sobel.sobel_vert[i][j] = -2.0 / norm;
				}
				// else upper half:
				else {
					sobel.sobel_vert[i][j] = 2.0 / norm;
				}
			}
			// else if bottom half:
			else if (i > middle) {
				sobel.sobel_vert[i][j] = -1.0 / norm;
			}
			// else upper half:
			else {
				sobel.sobel_vert[i][j] = 1.0 / norm;
			}
		}
	}
	
	return sobel;
}
