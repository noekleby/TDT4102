//
//  oppg3.h
//  Øving 8
//
//  Created by Magnus Pedersen on 14.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_8__oppg3__
#define ___ving_8__oppg3__

#include <iostream>
#include <string>
#include <cmath>
#include "Image.h"


/*class Shape
{
private:
    std::string color;
    std::string line;
public:
    Shape(std::string color, std::string line);    //Constructor
    void setColor(std::string color);            //Used to change the color
    void setLine(std::string line);                //Used to change the line type
    std::string getColor();                        //Returns the color
    std::string getLine();                        //Returns the line type
    virtual std::string toString();                //Returns a string that descibes the shape in this format "Color = blue, Line = dotted"
    virtual std::string getName() = 0;
};*/
class Shape
{
private:
    Color c;
public:
    Shape()
    {
        c.red = 0; c.blue = 0; c.green = 0;
    }
    Shape(unsigned char red, unsigned char green, unsigned char blue)
    {
        c.red = red; c.blue = blue; c.green = green;
    }
    Shape(Color color)
    {
        c = color;
    }
    virtual void draw(Image& image) = 0;
    Color getColor()
    {
        return c;
    }
};

#endif /* defined(___ving_8__oppg3__) */
