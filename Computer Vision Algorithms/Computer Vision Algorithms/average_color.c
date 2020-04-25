//
//  average_color.c
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/25/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#include "average_color.h"
#include <stdio.h>



/*
Function Description: estimates average color (HSV) values of possible objects in an image.
Inputs:
	pic = raw image
		type: struct RGB_image
	edges = list of edges in image, sorted from left to right
		type: struct edge_list
Outputs:
	object_colors = average color (HSV) values of possible objects in an image
		type: struct obj_avg_colors
*/
struct object_avg_colors estimate_avg_color(struct RGB_image pic, struct edge_list edges) {
	// average colors of possible objects:
	struct object_avg_colors object_colors;
	
	// iterate over MAX_EDGES-1 possible objects:
	for (int e=0; e<MAX_EDGES-1; e++) {
		// get left edge:
		struct edge left_edge = edges.edge_array[e];
		// get right edge:
		struct edge right_edge = edges.edge_array[e+1];
		
		// determine top and bottom limits of polygon:
		// int top_limit = 2nd smallest pixel row number
		// int bottom_limit = 2nd largest pixel row number
		
		// estimate average color (HSV) values of (possible) object:
		// for (int row=top_limit; row<=bottom_limit; row++) {
				// left limit line:
				
				// left limit:
				// int left = round(left_slope*row + left_intercept)
				// right limit:
				// int right = round(right_slope*row + right_intercept)
	}
	
	
	return object_colors;
}
