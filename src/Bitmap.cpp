#include <cstdint>
#include <fstream>
#include <vector>
#include "BmpHeaders.h"
#include "Bitmap.h"

void Bitmap::drawBitmap(std::vector<std::vector<int>> set) {
    int width = set[0].size();
    int height = set.size();
    int rowStride = (width * 3 + 3) & ~3;
    int maxPointValue = 0;

    for (const auto& row : set) {
        for (auto point : row) {
            maxPointValue = point > maxPointValue ? point : maxPointValue;
        }
    }

    std::vector<uint8_t> pixelData(rowStride * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int point = set[i][j];

            uint8_t b, g, r = 0;

            if (point != -1) {
                double t = static_cast<double>(point) / maxPointValue;
                r = static_cast<uint8_t>(9 * (1 - t) * t * t * t * 255);
                g = static_cast<uint8_t>(15 * (1 - t) * (1 - t) * t * t * 255);
                b = static_cast<uint8_t>(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
            }

            // Blue
            pixelData[i * rowStride + j * 3 + 0] = b;
            // Green
            pixelData[i * rowStride + j * 3 + 1] = g;
            // Red
            pixelData[i * rowStride + j * 3 + 2] = r;
        }
    }

    writeToFile(width, height, pixelData);
}

void Bitmap::writeToFile(int width, int height, std::vector<uint8_t> pixelData) {
    int pixelDataSize = pixelData.size();
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.rawBitmapDataSize = pixelDataSize;
    fileHeader.fileSize = fileHeader.offsetData + pixelDataSize;

    std::ofstream fout("image.bmp", std::ios::binary);
    fout.write(reinterpret_cast<const char *>(&fileHeader), sizeof(fileHeader));
    fout.write(reinterpret_cast<const char *>(&infoHeader), sizeof(infoHeader));
    fout.write(reinterpret_cast<const char *>(pixelData.data()), pixelDataSize);
    fout.close();
}
