//
//  main.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/4/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include <stdio.h>
#include "structs_and_constants.h"
#include "edge_detection.h"



// /*
int main() {
	// hyperparameters:
	float sigma = 1.0;
	int suppress_length = 2;
	int low_thresh = 5;
	int high_thresh = 10;
	int vert_scan_length = 2;
	int horiz_scan_length = 1;
	int min_edge_length = 5;
	// hyperparameter constants (in structs_and_constants.h):
	// #define KERNEL_SIZE 3
	// #define MAX_EDGES 10
	
    printf("\nModified Canny Edge Detection Algorithm:\n\n\n");
	
	
	// test input image:
	float raw_image[NUM_COLORS][NUM_ROWS][NUM_COLS];
	// fill input image array:
	for (int color=0; color<NUM_COLORS; color++) {
		for (int i=0; i<NUM_ROWS; i++) {
			for (int j=0; j<NUM_COLS; j++) {
				if ( (i < NUM_ROWS/2 && i == j) || (i >= NUM_ROWS/2 && i == NUM_COLS-j) ) {
					raw_image[color][i][j] = 255.0;
				}
				else {
					raw_image[color][i][j] = 0.0;
				}
			}
		}
	}
	
	// perform modified Canny edge detection:
	struct edge_list edges = canny_edge_detection(raw_image, sigma, suppress_length, low_thresh, high_thresh, vert_scan_length, horiz_scan_length, min_edge_length);
	
	// display edges:
	for(int e=0; e<edges.num_edges; e++) {
		printf("Edge %d:	", e+1);
		printf("Top vertex: (%d, %d);  ", edges.edge_array[e].top.row+1, edges.edge_array[e].top.col+1);
		printf("Middle vertex: (%d, %d);  ", edges.edge_array[e].middle.row+1, edges.edge_array[e].middle.col+1);
		printf("Bottom vertex: (%d, %d)\n", edges.edge_array[e].bottom.row+1, edges.edge_array[e].bottom.col+1);
	}
	
	
	printf("\n\n");
    return 0;
}
// */
