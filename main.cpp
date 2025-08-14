#include <iostream>
#include <complex>
#include <bits/stdc++.h>
#include <cmath>
#include "Bitmap.h"

constexpr uint8_t NUM_OF_ITERATIONS = 500;
constexpr double ITERATION_STEP = 0.005;
const std::complex<double> c(0.285, 0.01);

std::complex<double> f(std::complex<double> z) {
    return (z * z) + c;
}

int main() {
    int numOfIterations = NUM_OF_ITERATIONS;

    std::vector<std::vector<std::complex<double>>> points;
    std::vector<std::vector<int>> iterationCount;
    double x = -2.0;
    while(x <= 2) {
        std::vector<std::complex<double>> row;
        std::vector<int> iterRow;

        double y = -2.0;
        while (y <= 2) {
            std::complex<double> point(x, y);
            row.push_back(point);
            iterRow.push_back(-1);
            y += ITERATION_STEP;
        }
        points.push_back(row);
        iterationCount.push_back(iterRow);
        x += ITERATION_STEP;
    }

    while(numOfIterations > 0) {
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points[i].size(); j++) {
                std::complex<double> z = f(points[i][j]);
                if (abs(z) > 2) {
                    if (iterationCount[i][j] == -1) {
                        iterationCount[i][j] = NUM_OF_ITERATIONS - numOfIterations;
                    }
                    continue;
                }
                points[i][j] = z;
            }
        }
        --numOfIterations;
    }

    Bitmap::drawBitmap(iterationCount);

    return 0;
}
