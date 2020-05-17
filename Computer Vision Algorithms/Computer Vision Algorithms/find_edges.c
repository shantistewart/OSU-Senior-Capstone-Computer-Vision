//
//  find_edges.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/25/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "find_edges.h"
#include <stdio.h>



/*
Function Description: finds long vertical edges with hysteresis thresholding for edge continuity.
Inputs:
	grads = gradient image
		type: struct image
	low_thresh = lower gradient value threshold (0-255)
	high_thresh = higher gradient value threshold (0-255)
	vert_scan_length = vertical "scanning" length for edge continuity
	horiz_scan_length = horizontal "scanning" length for edge continuity
	min_edge_length = minimum edge length to keep
Outputs:
	edges = list of edges in image, unsorted
		type: struct edge_list
*/
struct edge_list find_edges(struct image grads, int low_thresh, int high_thresh, int vert_scan_length, int horiz_scan_length, int min_edge_length) {
	// array of edges:
	struct edge_list edges;
	
	// top (start) vertex:
	struct vertex top;
	// bottom (stop) vertex:
	struct vertex bottom;
	// pixel that is farthest to the left:
	struct vertex most_left;
	// pixel that is farthest to the right:
	struct vertex most_right;
	// current pixel coordinates:
	struct vertex current_pixel;
	
	// search over entire image:
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			// start of an edge must be above high threshold:
			if (grads.pixels[i][j] >= high_thresh) {
				// record top (start) vertex:
				top.row = i;
				top.col = j;
				// initialize farthest left and and right vertices:
				most_left = top;
				most_right = top;
				
				// Bool for edge continuation:
				int connect = 1;
				// starting pixel:
				current_pixel = top;
				// travel down (or down-left or down-right) potential edge:
				while (connect == 1 && current_pixel.col >= 0 && current_pixel.col < NUM_COLS) {
					// keep rolling maximums of farthest left and right vertices:
					if (current_pixel.col < most_left.col) {
						most_left = current_pixel;
					}
					if (current_pixel.col > most_right.col) {
						most_right = current_pixel;
					}
					
					// scan down edge, using hysteresis thresholding for edge continuation:
				}
			}
		}
	}
	
	
	return edges;
}
