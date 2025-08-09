#include <cstdint> 
#include <fstream>

struct BMPHeader {
    char bitmapSigantureBytes[2] = {'B', 'M'};
    // header + infoHeader + width * height * colorsNum
    uint32_t sizeOfBitmapFile = 14 + 40 + 512 * 512 * 3;
    uint32_t reservedBytes = 0;
    uint32_t pixelDataOffset = 54;

} bmpHeader;

struct BMPInfoHeader {
    uint32_t sizeOfThisHeader = 40;
    int32_t width = 512;
    int32_t height = 512;
    uint16_t numberOfColorPlanes = 1;
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0;
    int32_t horizontalResolution = 3780;
    int32_t verticalResolution = 3780;
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;
} bmpInfoHeader;

struct Pixel {
    uint8_t blue = 255;
    uint8_t green = 255;
    uint8_t red = 0;
} pixel;


int main() {
    std::ofstream fout("image.bmp", std::ios::binary);

    fout.write((char *) &bmpHeader, 14);
    fout.write((char *) &bmpInfoHeader, 14);


    size_t numberOfPixels = bmpInfoHeader.width * bmpInfoHeader.height;
    for (int i = 0; i < numberOfPixels; i++) {
        fout.write((char *) &pixel, 3);
    }
    fout.close();

    return 0;
}