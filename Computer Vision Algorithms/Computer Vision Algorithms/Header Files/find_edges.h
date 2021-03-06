//
//  find_edges.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/25/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef find_edges_h
#define find_edges_h


#include "structs_and_constants.h"



/*
Function Description: finds long vertical edges with hysteresis thresholding for edge continuity.
Inputs:
	grads = gradient image
		type: struct image
	low_thresh = lower gradient value threshold (0-255 pixel intensity)
	high_thresh = higher gradient value threshold (0-255 pixel intensity)
	vert_scan_length = vertical "scanning" length for edge continuity
	horiz_scan_length = horizontal "scanning" length for edge continuity
	min_edge_length = minimum edge length to keep
Outputs:
	edges = list of edges in image, unsorted
		type: struct edge_list
*/
struct edge_list find_edges(struct image grads, int low_thresh, int high_thresh, int vert_scan_length, int horiz_scan_length, int min_edge_length);



#endif /* find_edges_h */
