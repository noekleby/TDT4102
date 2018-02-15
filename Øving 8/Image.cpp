//
//  Image.cpp
//  Øving 8
//
//  Created by Magnus Pedersen on 14.03.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "Image.h"
Image::Image( unsigned int width, unsigned int height )
{
    this->width = width;
    this->height = height;
    data = new unsigned char[height*width*3];
    for (int i = 0; i < (height*width*3); i++)
    {
        data[i] = char(0); //konverterer 0 til null character
    }
}
Image::~Image()
{
    delete [] data;
    data = nullptr;
}
unsigned int Image::GetHeight() const
{
    return height;
}
unsigned int Image::GetWidth() const
{
    return width;
}
const unsigned char *Image::GetScanLine(unsigned int line) const //returnerer første piksel
{
    return &data[width*line*3];
}
unsigned char *Image::GetScanLine(unsigned int line)
{
    return &data[width*line*3];
}
void Image::SetColor( unsigned int x, unsigned int y, const Color &color )
{
    //x=kolonne, y=rad, origo er nede i venstre hjørne på fargekartet
    if (x < width && y < height)
    {
        data[(y * (this->GetWidth()) + x)*3] = color.red;
        data[(y * (this->GetWidth()) + x)*3 + 1] = color.green;
        data[(y * (this->GetWidth()) + x)*3 + 2] = color.blue;
    }
}
Color Image::GetColor( unsigned int x, unsigned int y ) const
{
    Color value;
    if (x < width && y < height)
    {
        value.red = data[(y * width + x)*3];
        value.green = data[(y * width + x)*3+1];
        value.blue = data[(y * width + x)*3+2];
    }
    return value;
}
void Image::Fill( const Color &color )
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            SetColor(i, j, color);
        }
    }
}

