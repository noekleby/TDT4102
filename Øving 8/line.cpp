//
//  line.cpp
//  Øving 8
//
//  Created by Magnus Pedersen on 21.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "line.h"
Line::Line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, Color c)
:x1(x1), y1(y1), x2(x2), y2(y2), Shape(c){}

void Line::Draw(Image& img){
    
	//Check start conditions
	if (x2 < x1){
		std::swap(x1, x2);
		std::swap(y1, y2);
	}
    
	//Calculate dimensions
	int dx = x2 - x1;
	int dy = y2 - y1;
	int linewidth = dx;
	int lineheight = dy;
	if (dx < 0)
		linewidth = -dx;
	if (dy < 0)
		lineheight = -dy;
    
	//Draw straight lines
	if (!lineheight){
		for (unsigned int x = x1; x <= x2; x++){
			img.SetColor(x, y1, getColor());
		}
	}
	else if (!linewidth){
		for (unsigned int y = y1; y <= y2; y++){
			img.SetColor(x1, y, getColor());
		}
	}
    
	//Draw diagonal lines -45 to 45 degrees
	else if (lineheight<=linewidth){
		for (unsigned int x = x1; x <= x2; x++){
			double y;
			y = dy;
			y /= dx;
			y *= (x - x1);
			y += y1;
			img.SetColor(x, y, getColor());
		}
	}
    
	//Draw steep lines
	else{
        
		//Set start and stop
		unsigned int start = y1, stop = y2;
        
		//Avoid rounding off
		double yD1 = y1, yD2 = y2;
        
		//Compensate for-loop for downward slopes
		if (dy < 0)
			std::swap(start, stop);
		
		for (unsigned int y = start; y <= stop; y++){
			double x;
			x = (x2 - x1);
			x /= (yD2 - yD1);
			x *= (y - yD1);
			x += x1;
			img.SetColor(x, y, getColor());
		}
	}
}