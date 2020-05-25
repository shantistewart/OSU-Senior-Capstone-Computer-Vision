//
//  edge_detection.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 5/24/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "edge_detection.h"
#include "blur_filter.h"
#include "estimate_grad.h"
#include "non_max_suppress.h"
#include "find_edges.h"



/*
Function Description: performs a modified version of the Canny edge detection algorithm.
Inputs:
	raw_image = raw RGB image
		size: (NUM_COLORS, NUM_ROWS, NUM_COLS)
	sigma = standard deviation of Gaussian kernel, in step 1
	suppress_length = (half) horizontal "suppression" length, in step 3
	low_thresh = lower gradient value threshold (0-255 pixel intensity), in step 4
	high_thresh = higher gradient value threshold (0-255 pixel intensity), in step 4
	vert_scan_length = vertical "scanning" length for edge continuity, in step 4
	horiz_scan_length = horizontal "scanning" length for edge continuity, in step 4
	min_edge_length = minimum edge length to keep, in step 4
Outputs:
	edges = list of edges in image, unsorted
		type: struct edge_list
*/
struct edge_list canny_edge_detection(float raw_image[NUM_COLORS][NUM_ROWS][NUM_COLS], float sigma, int suppress_length, int low_thresh, int high_thresh, int vert_scan_length, int horiz_scan_length, int min_edge_length) {
	// wrap raw image values into a RGB_image struct:
	struct RGB_image raw_pic;
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				raw_pic.pixels[color][i][j] = raw_image[color][i][j];
			}
		}
	}
	
	
	// STEP 1: GAUSSIAN BLUR FILTER
	struct RGB_image blur_pic = blur_filter(raw_pic, sigma);
	printf("\nFinished Gaussian blur filter step!\n");
	
	// STEP 2: GRADIENT ESTIMATION
	// to normalize Sobel operators:
	int norm = 1;
	struct image grads = estimate_grad(blur_pic, norm);
	printf("Finished gradient estimation step!\n");
	
	// STEP 3: HORIZONTAL NON-MAXIMAL SUPPRESSION
	struct image suppress_grads = non_max_suppress(grads, suppress_length);
	printf("Finished horizontal non-maximal suppression step!\n");
	
	// STEP 4: LONG VERTICAL EDGE DETERMINATION
	struct edge_list edges = find_edges(suppress_grads, low_thresh, high_thresh, vert_scan_length, horiz_scan_length, min_edge_length);
	printf("Finished long vertical edge determination suppression step!\n\n");
	
	
	return edges;
}
