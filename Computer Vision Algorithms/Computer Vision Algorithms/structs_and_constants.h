//
//  structs_and_constants.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/5/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef structs_and_constants_h
#define structs_and_constants_h



// number of color channels:
#define NUM_COLORS 3
// number of rows of image pixels:
#define NUM_ROWS 3
// number of columns of image pixels:
#define NUM_COLS 4
// size of Gaussian kernel (must be odd!):
#define KERNEL_SIZE 3
// size of Sobel operators (must be odd!):
#define SOBEL_SIZE 3
// max number of edges in an image:
#define MAX_EDGES 10


// RGB image pixel values:
struct RGB_image {
	float pixels[NUM_COLORS][NUM_ROWS][NUM_COLS];
};

// image (1 color channel) pixel values:
struct image {
	float pixels[NUM_ROWS][NUM_COLS];
};

// Gaussian kernel matrix:
struct gaussian_kernel {
	float kernel_matrix[KERNEL_SIZE][KERNEL_SIZE];
};

// Sobel operator matrices:
struct sobel_operators {
	// horizontal gradient Sobel kernel (for vertical edges):
	float sobel_horiz[SOBEL_SIZE][SOBEL_SIZE];
	// % vertical gradient Sobel kernel (for horizontal edges):
	float sobel_vert[SOBEL_SIZE][SOBEL_SIZE];
};

// vertex coordinates:
struct vertex {
	// pixel row number:
	int x;
	// pixel column number:
	int y;
};

// 3-vertex edge:
struct edge {
	struct vertex top;
	struct vertex middle;
	struct vertex bottom;
};

// array of edges (for an image):
struct edge_list {
	struct edge edge_verts[MAX_EDGES];
};

// average color (HSV) values for an object:
struct avg_color {
	// hue:
	float h;
	// saturation:
	float s;
	// value:
	float v;
};

// array of average color (HSV) values for possible objects in an image:
struct object_avg_colors {
	struct avg_color avg_colors[MAX_EDGES-1];
};



#endif /* structs_and_constants_h */
