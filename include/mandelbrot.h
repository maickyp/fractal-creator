#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace Fractal{

    class Mandelbrot{
        public:
        Mandelbrot();
        virtual ~Mandelbrot();
        static const int MAX_ITERATIONS = 1000;

        static int getIterations(double x, double y);
    };

}

#endif // MANDELBROT_H_