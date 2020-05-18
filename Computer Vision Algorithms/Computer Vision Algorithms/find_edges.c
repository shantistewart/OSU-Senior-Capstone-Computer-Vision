//
//  find_edges.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/25/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "find_edges.h"
#include <stdio.h>
#include "utility_functions.h"



/*
Function Description: finds long vertical edges with hysteresis thresholding for edge continuity.
Inputs:
	grads = gradient image
		type: struct image
	low_thresh = lower gradient value threshold (0-255)
	high_thresh = higher gradient value threshold (0-255)
	vert_scan_length = vertical "scanning" length for edge continuity
	horiz_scan_length = half horizontal "scanning" length for edge continuity
	min_edge_length = minimum edge "length" to keep
Outputs:
	edges = list of edges in image, unsorted
		type: struct edge_list
*/
struct edge_list find_edges(struct image grads, int low_thresh, int high_thresh, int vert_scan_length, int horiz_scan_length, int min_edge_length) {
	// array of edges:
	struct edge_list edges;
	edges.num_edges = 0;
	
	// top (start) vertex:
	struct vertex top;
	// bottom (stop) vertex:
	struct vertex bottom;
	// pixel that is farthest to the left:
	struct vertex most_left;
	// pixel that is farthest to the right:
	struct vertex most_right;
	// average of top and bottom vertices:
	struct vertex top_bottom_avg;
	// current pixel coordinates:
	struct vertex current_pixel;
	// subarray for edge scanning:
	float subarray[vert_scan_length][2*horiz_scan_length + 1];
	
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
				while(connect == 1 && current_pixel.row < NUM_ROWS-vert_scan_length && current_pixel.col >= horiz_scan_length && current_pixel.col < NUM_COLS-horiz_scan_length) {
					// keep rolling maximums of farthest left and right vertices:
					if (current_pixel.col < most_left.col) {
						most_left = current_pixel;
					}
					if (current_pixel.col > most_right.col) {
						most_right = current_pixel;
					}
					
					// extract subarray to scan down edge:
					for (int k = 0; k < vert_scan_length; k++) {
						for (int l = 0; l < 2*horiz_scan_length+1; l++) {
							subarray[k][l] = grads.pixels[current_pixel.row + 1 + k][current_pixel.col - horiz_scan_length + l];
						}
					}
					// take max element in scan subarray:
					struct arg_max max_elem = arg_maximum(vert_scan_length, 2*horiz_scan_length+1, subarray);
					// continue edge if above low threshold:
					if (max_elem.max >= low_thresh) {
						// move to max pixel:
						current_pixel = max_elem.coord;
					}
					// else end edge:
					else {
						connect = 0;
					}
				}
				// record bottom (stop) vertex:
				bottom = current_pixel;
				
				// save edge if its L1-norm is large enough:
				if (L1_norm_int(top.row - bottom.row, top.col - bottom.col) >= min_edge_length) {
					// keep middle (corner) vertex that is vertically closest and horizontally farthest from the average of the top and bottom vertices:
					top_bottom_avg.row = (top.row + bottom.row) / 2;
					top_bottom_avg.col = (top.col + bottom.col) / 2;
					
					// edges.edge_array[edges.num_edges]
					edges.num_edges++;
				}
			}
		}
	}
	
	
	return edges;
}
