//
//  edge_detection.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 5/24/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef edge_detection_h
#define edge_detection_h


#include <stdio.h>
#include "structs_and_constants.h"



/*
Function Description: performs a modified version of the Canny edge detection algorithm.
Inputs:
	raw_image = raw RGB image
		size: (NUM_COLORS, NUM_ROWS, NUM_COLS)
	sigma = standard deviation of Gaussian kernel
	suppress_length = (half) horizontal "suppression" length
	low_thresh = lower gradient value threshold (0-255 pixel intensity)
	high_thresh = higher gradient value threshold (0-255 pixel intensity)
	vert_scan_length = vertical "scanning" length for edge continuity
	horiz_scan_length = horizontal "scanning" length for edge continuity
	min_edge_length = minimum edge length to keep
Outputs:
	edges = list of edges in image, unsorted
		type: struct edge_list
*/
struct edge_list canny_edge_detection(float raw_image[NUM_COLORS][NUM_ROWS][NUM_COLS], float sigma, int suppress_length, int low_thresh, int high_thresh, int vert_scan_length, int horiz_scan_length, int min_edge_length);



#endif /* edge_detection_h */
