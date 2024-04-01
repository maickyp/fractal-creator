#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>

namespace CustomBitMap{

    struct Zoom {
        int x{0};
        int y{0};
        double scale{0.0};
        Zoom(int x, int y, double scale) : x(x), y(y), scale(scale){};
    };


    class ZoomList{
        private:
        int m_width{0};
        int m_height{0};
        std::vector<Zoom> zooms;

        double m_xCenter{0};
        double m_yCenter{0};
        double m_scale{1.0};

        public:
        ZoomList (int width, int height);
        virtual ~ZoomList();

        void add(const Zoom& zoom);
        std::pair<double, double> doZoom(int x, int y);
    };

    
}

#endif // ZOOMLIST_H_