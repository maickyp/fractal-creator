#include <iostream>
#include <stdio.h>
#include <cstdint>
#include <memory>
#include <math.h>

#include "fractalCreator.h"

int main(){

    const int WIDTH = 800;
    const int HEIGHT = 600;

    Fractal::FractalCreator FractalCreator(WIDTH, HEIGHT);

    FractalCreator.run("out\\base.bmp");
    FractalCreator.addZoom(CustomBitMap::Zoom(295, HEIGHT - 202, 0.1));
    FractalCreator.run("out\\zoom1.bmp");
    FractalCreator.addZoom(CustomBitMap::Zoom(312, HEIGHT - 304, 0.1));
    FractalCreator.run("out\\zoom2.bmp");
    

    return 0;
}