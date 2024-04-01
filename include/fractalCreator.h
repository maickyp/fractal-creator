#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>

#include "mandelbrot.h"
#include "bitmap.h"
#include "zoomList.h"

namespace Fractal{
    struct RGB{
        double red;
        double green;
        double blue;
        RGB(double red, double green, double blue): red(red), green(green),  blue(blue){};
    };

    class FractalCreator{
        private:
        int m_width{0};
        int m_height{0};
        long m_totalIterations{0};
        std::vector<int> m_ranges;
        std::vector<RGB> m_colors;

        CustomBitMap::ZoomList m_zoomList{m_width, m_height};
        CustomBitMap::Bitmap m_image{m_width, m_height};
        std::unique_ptr<int[]> m_histogram{nullptr};
        std::unique_ptr<int[]> m_fractal{nullptr};
        
        void calculateIterations();
        void calculateTotalIterations();
        void drawFractal();
        void writeBitMap(std::string name);


        public:
        FractalCreator(int width, int heigh);
        virtual ~FractalCreator();

        void addZoom(const CustomBitMap::Zoom& zoom);
        void run(std::string name);


    };


}

#endif