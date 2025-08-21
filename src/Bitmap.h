#pragma once
#include <cstdint> 
#include <vector>

class Bitmap {
public:
    static void drawBitmap(std::vector<std::vector<int>> set);

private:
    static void writeToFile(int width, int height, std::vector<uint8_t> pixelData);
};
