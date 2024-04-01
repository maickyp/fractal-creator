#include "bitmap.h"
#include "bitmapFileHeader.h"
#include "bitmapInfoHeader.h"
#include <stdio.h>
#include <fstream>


namespace CustomBitMap{

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[m_width*m_height*3]{0}){

};

Bitmap::~Bitmap(){

};

bool Bitmap::write(std::string filename){
    BitMapFileHeader fileHeader;
    BitMapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitMapFileHeader)+ sizeof(BitMapInfoHeader) + m_width*m_height*3;
    
    fileHeader.dataOffset = sizeof(BitMapFileHeader)+ sizeof(BitMapInfoHeader); // Where actual pixel data starts

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    std::ofstream file;
    file.open(filename, std::ios::out|std::ios::binary);
    if(!file){
        return false;
    }

    file.write((char *) &fileHeader, sizeof(fileHeader));
    file.write((char *) &infoHeader, sizeof(infoHeader));
    file.write((char *) m_pPixels.get(), m_width*m_height*3);

    file.close();


    return true;
};

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
    uint8_t * pixel = m_pPixels.get();
    pixel += (y*3)*m_width + (x*3);
    *pixel = blue;
    pixel++;
    *pixel = green;
    pixel++;
    *pixel = red;

    //It also can be don as  follow
    // pixel[0] = blue
    // pixel[1] = green
    // pixel[2] = red
};

}