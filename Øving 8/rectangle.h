//
//  rectangle.h
//  Øving 8
//
//  Created by Magnus Pedersen on 21.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_8__rectangle__
#define ___ving_8__rectangle__

#include <iostream>
#include "oppg3.h"
#include "Image.h"
#include "Line.h"

class Rectangle : public Shape {
private:
	Line diagonal;
public:
	Rectangle(Line);
	void Draw(Image&);
};
#endif /* defined(___ving_8__rectangle__) */
