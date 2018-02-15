//
//  line.h
//  Øving 8
//
//  Created by Magnus Pedersen on 21.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_8__line__
#define ___ving_8__line__

#include <iostream>
#include "oppg3.h"
#include "Image.h"

class Line : public Shape
{
public:
	Line(unsigned int, unsigned int, unsigned int, unsigned int, Color);
	unsigned int x1, y1, x2, y2;
	void Draw(Image&);
};
#endif /* defined(___ving_8__line__) */
