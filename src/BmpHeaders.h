#pragma once
#include <cstdint>

#pragma pack(push, 1)

// File header 14 bytes
struct BITMAPFILEHEADER {
    // 0x42 0x4D - "BM" 
    uint16_t fileType{0x4D42};
    uint32_t fileSize{0};
    // Reserved fields are for some additiona info
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    // Offset is information where actual image starts
    uint32_t offsetData{54};

};

// Image with information about image
struct BITMAPINFOHEADER {
    uint32_t sizeOfThisHeader{40};
    int32_t width{512};
    int32_t height{512};
    // It always will be 1 its legacy of some old GPUs
    uint16_t numberOfColorPlanes{1};
    // in RGB 24 = 8 bits per color
    uint16_t colorDepth{24};
    uint32_t compressionMethod{0};
    uint32_t rawBitmapDataSize{0};
    // Resolution in pixels on one meter
    int32_t horizontalResolution{3780};
    int32_t verticalResolution{3780};
    // 0 = full color pallet
    uint32_t colorTableEntries{0};
    uint32_t importantColors{0};
};

#pragma pack(pop)