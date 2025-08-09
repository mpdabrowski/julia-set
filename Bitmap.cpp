#include <cstdint> 
#include <fstream>
#include <vector>
#include "BmpHeaders.h"
#include "Bitmap.h"

Bitmap::Bitmap(int width, int height) {
    width_ = width;
    height_ = height;
}

void Bitmap::drawBitmap(std::vector<std::vector<int>> set) {
    int rowStride = (width_ * 3 + 3) & ~3;

    std::vector<uint8_t> pixelData(rowStride * height_);
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            // Blue
            pixelData[i * rowStride + j * 3 + 0] = 0;
            // Green
            pixelData[i * rowStride + j * 3 + 1] = 0;
            // Red
            pixelData[i * rowStride + j * 3 + 2] = (j % 256);
        }
    }

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    infoHeader.width = width_;
    infoHeader.height = height_;
    infoHeader.rawBitmapDataSize = pixelData.size();
    fileHeader.fileSize = fileHeader.offsetData + pixelData.size();

    std::ofstream fout("image.bmp", std::ios::binary);

    fout.write(reinterpret_cast<const char *>(&fileHeader), sizeof(fileHeader));
    fout.write(reinterpret_cast<const char *>(&infoHeader), sizeof(infoHeader));
    fout.write(reinterpret_cast<const char *>(pixelData.data()), pixelData.size());

    fout.close();
}
