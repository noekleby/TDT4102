//
//  rectangle.cpp
//  Øving 8
//
//  Created by Magnus Pedersen on 21.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "rectangle.h"

Rectangle::Rectangle(Line diagonal) : Shape(diagonal.getColor()), diagonal(diagonal) {}

void Rectangle::Draw(Image& img){
	Line d = diagonal; //Just compressing the code
	Line left(d.x1, d.y1, d.x1, d.y2, getColor()),
    right(d.x2, d.y1, d.x2, d.y2, getColor()),
    lower(d.x1, d.y1, d.x2, d.y1, getColor()),
    upper(d.x1, d.y2, d.x2, d.y2, getColor());
	left.Draw(img);
	right.Draw(img);
	lower.Draw(img);
	upper.Draw(img);
}