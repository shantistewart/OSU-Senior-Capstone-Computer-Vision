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
		
		// rolling sum of number of pixels in (possible ) object:
		int num_pixels = 0;
		// rolling sum of colors:
		struct color color_sum;
		color_sum.h = 0.0;
		color_sum.s = 0.0;
		color_sum.v = 0.0;
		
		// estimate average color (HSV) values of (possible) object:
		// for (int row=top_limit; row<=bottom_limit; row++) {
				// estimate left limit line:
				// if upper half of left edge:
				// if (row <= left_edge.middle.row) {
						// struct line left_line = approx_line(left_edge.top, left_edge.middle);
				// }
				// else lower half of left edge:
				// else {
						// struct line left_line = approx_line(left_edge.middle, left_edge.bottom);
				// }
				
				// estimate right limit line:
				// if upper half of right edge:
				// if (row <= right_edge.middle.x) {
						// struct line right_line = approx_line(right_edge.top, right_edge.middle);
				// }
				// else lower half of right edge:
				// else {
						// struct line right_line = approx_line(right_edge.middle, right_edge.bottom);
				// }
				
				// left limit:
				// int left = round(left_line.slope*row + left_line.intercept);
				// right limit:
				// int right = round(right_line.slope*row + right_line.intercept);
				
				// calculate sum of colors in row:
				// for (int col=left; col<=right; col++) {
						// color_sum.h = color_sum.h + pic[0][row][col];
						// color_sum.s = color_sum.s + pic[1][row][col];
						// color_sum.v = color_sum.v + pic[2][row][col];
				// }
		
		// calculate average color values:
		object_colors.avg_colors[e].h = color_sum.h / num_pixels;
		object_colors.avg_colors[e].s = color_sum.s / num_pixels;
		object_colors.avg_colors[e].v = color_sum.v / num_pixels;
	}
	
	
	return object_colors;
}
