#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_
#include <cstdint>

using namespace std;


#pragma pack(2)

namespace CustomBitMap{
    struct BitMapFileHeader{
        uint8_t header[2]{'B','M'};
        uint32_t fileSize{0};
        uint32_t reserved{0};
        uint32_t dataOffset{0};
    };

}
#pragma pack(0)

#endif //BITMAPFILEHEADER_H