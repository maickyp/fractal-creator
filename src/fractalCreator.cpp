#include "fractalCreator.h"
#include "mandelbrot.h"
#include <memory>
#include <math.h>

namespace Fractal{

FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height){
    m_histogram = std::unique_ptr<int[]>(new int[Mandelbrot::MAX_ITERATIONS]{0});
    m_fractal = std::unique_ptr<int[]>(new int[m_width*m_height]{0});
    addZoom(CustomBitMap::Zoom(m_width/2, m_height/2, 4.0/m_width));
};
FractalCreator::~FractalCreator(){

};

void FractalCreator::calculateIterations(){
    for(int y = 0; y < m_height; y++){
        for(int x = 0; x < m_width; x++){
            std::pair<double, double> xyfractal = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(xyfractal.first, xyfractal.second);
            
            m_fractal[y*m_width+x] = iterations;
            
            if (iterations != Mandelbrot::MAX_ITERATIONS){
                m_histogram[iterations]++;
            }
        }
    }
};

void FractalCreator::drawFractal(){

    for(int y = 0; y < m_height; y++){
        for(int x = 0; x < m_width; x++){
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = m_fractal[y*m_width+x];
            double hue = 0.0;
            for (int i =0; i<= iterations; i++){
                hue+= (double) m_histogram[i]/m_totalIterations;
            }

            green = pow(255, hue);


            m_image.setPixel(x,y, red, green, blue);
        }
    }
};

void FractalCreator::addZoom(const CustomBitMap::Zoom& zoom){
    m_zoomList.add(zoom);
};

void FractalCreator::writeBitMap(std::string name){
    m_image.write(name);
};

void FractalCreator::calculateTotalIterations(){
    m_totalIterations = 0;
    for(int i = 0; i<Mandelbrot::MAX_ITERATIONS; i++){
        m_totalIterations += m_histogram[i];
    }
}

void FractalCreator::run(std::string name){
    calculateIterations();
    calculateTotalIterations();
    drawFractal();
    writeBitMap(name);
}
}