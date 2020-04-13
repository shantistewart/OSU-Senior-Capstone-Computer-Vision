//
//  structs_and_constants.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef structs_and_constants_h
#define structs_and_constants_h



// size of Gaussian kernel (must be odd!):
#define KERNEL_SIZE 3
// number of color channels:
#define NUM_COLORS 3
// number of rows of image pixels:
#define NUM_ROWS 4
// number of columns of image pixels:
#define NUM_COLS 4


// Gaussian kernel matrix:
struct gaussian_kernel {
	float kernel_matrix[KERNEL_SIZE][KERNEL_SIZE];
};

// RGB image pixel values:
struct RGB_image {
	float pixels[NUM_COLORS][NUM_ROWS][NUM_COLS];
};

// image (1 color channel) pixel values:
struct image {
	float pixels[NUM_ROWS][NUM_COLS];
};



#endif /* structs_and_constants_h */
