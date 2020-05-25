//
//  find_edges.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/25/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "find_edges.h"
#include <stdio.h>
#include "structs_and_constants.h"
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
	// edge to add to array of edges:
	struct edge long_edge;
	
	// start (top) vertex:
	struct vertex start;
	// stop (bottom) vertex:
	struct vertex stop;
	// corner (middle) vertex:
	struct vertex corner;
	// pixel that is farthest to the left:
	struct vertex most_left;
	// pixel that is farthest to the right:
	struct vertex most_right;
	// average of stop and start vertices:
	struct vertex avg;
	// current pixel coordinates:
	struct vertex current_pixel;
	// subarray for edge scanning:
	float subarray[vert_scan_length][2*horiz_scan_length + 1];
	
	// search over entire image:
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<NUM_COLS; j++) {
			// start of an edge must be above high threshold:
			if (grads.pixels[i][j] >= high_thresh) {
				// record start (top) vertex:
				start.row = i;
				start.col = j;
				// initialize farthest left and and right vertices:
				most_left = start;
				most_right = start;
				
				// Bool for edge continuation:
				int connect = 1;
				// starting pixel:
				current_pixel = start;
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
				// record stop (bottom) vertex:
				stop = current_pixel;
				
				// save edge if its L1-norm is large enough:
				if (L1_norm_int(start.row - stop.row, start.col - stop.col) >= min_edge_length) {
					// average of start and stop vertices:
					avg.row = (start.row + stop.row) / 2;
					avg.col = (start.col + stop.col) / 2;
					// keep middle (corner) vertex that is horizontally farthest and vertically closest from the average of the top and bottom vertices:
					int left_quality = abs_int(most_left.col - avg.col) - abs_int(most_left.row - avg.row);
					int right_quality = abs_int(most_right.col - avg.col) - abs_int(most_right.row - avg.row);
					if (left_quality > right_quality) {
						corner = most_left;
					}
					else {
						corner = most_right;
					}
					
					// construct edge:
					long_edge.top = start;
					long_edge.middle = corner;
					long_edge.bottom = stop;
					
					edges.edge_array[edges.num_edges] = long_edge;
					edges.num_edges++;
					printf("\nnum_edges: %d\n", edges.num_edges);
				}
				
				// if max number of edges is reached return from function
				if (edges.num_edges == MAX_EDGES) {
					return edges;
				}
			}
		}
	}
	
	return edges;
}
