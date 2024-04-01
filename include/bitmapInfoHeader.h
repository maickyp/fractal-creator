#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_
#include <cstdint>

using namespace std;

#pragma pack(2)

namespace CustomBitMap{
    struct BitMapInfoHeader{
        uint32_t headerSize{40};
        int32_t width{0};
        int32_t height{0};
        uint16_t planes{1};
        uint16_t bitsPerPixel{24};
        uint32_t compression{0};
        uint32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        uint32_t colors{0};
        uint32_t importantColors{0};
    };
}
#pragma pack(0)

#endif //BITMAPINFOHEADER_H