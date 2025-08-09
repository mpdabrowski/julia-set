#pragma once
#include <cstdint> 
#include <vector>

class Bitmap {
public:
    Bitmap(int width, int height);
    void drawBitmap(std::vector<std::vector<int>> set);

private:
    int width_, height_;
};
