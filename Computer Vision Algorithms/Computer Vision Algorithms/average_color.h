//
//  average_color.h
//  Computer Vision Algorithms
//
//  Created by Shanti Stewart on 4/25/20.
//  Copyright © 2020 Shanti Stewart. All rights reserved.
//


#ifndef average_color_h
#define average_color_h


#include "structs_and_constants.h"



/*
Function Description: estimates average color (HSV) values of possible objects in an image.
Inputs:
	pic = raw image
		type: struct RGB_image
	edges = list of edges in image
		type: struct edge_list
Outputs:
	object_colors = average color (HSV) values of possible objects in an image
		type: struct obj_avg_colors
*/
struct object_avg_colors estimate_avg_color(struct RGB_image pic, struct edge_list edges);



#endif /* average_color_h */
