#include <iostream>
#include <complex>
#include <bits/stdc++.h>
#include <cmath>
#include "Bitmap.h"

constexpr uint8_t NUM_OF_ITERATIONS = 500;
constexpr double ITERATION_STEP = 0.007;
constexpr double START_VALUE = -2;
constexpr double STOP_VALUE = 2;
const std::complex<double> c(-0.70176, -0.3842);

std::complex<double> f(std::complex<double> z);

std::vector<std::vector<int>> getNumberOfIterationsPerPixel();

int main() {
    Bitmap::drawBitmap(getNumberOfIterationsPerPixel());

    return 0;
}

std::complex<double> f(std::complex<double> z) {
    return (z * z) + c;
}

/**
 * @TODO add parallel computation
 */
std::vector<std::vector<int>> getNumberOfIterationsPerPixel() {
    std::vector<std::vector<int>> iterationCount;

    double x = START_VALUE;
    while(x <= STOP_VALUE) {
        std::vector<int> iterRow;
        double y = START_VALUE;
        while (y <= STOP_VALUE) {
            std::complex<double> point(x, y);
            bool valueFind = false;
            int numOfIterations = NUM_OF_ITERATIONS;
            while(numOfIterations > 0) {
                point = f(point);
                if (abs(point) > 2) {
                    valueFind = true;
                    iterRow.push_back(NUM_OF_ITERATIONS - numOfIterations);
                    break;
                }
                --numOfIterations;
            }
            if (!valueFind) {
                iterRow.push_back(-1);
            }
            y += ITERATION_STEP;
        }
        iterationCount.push_back(std::move(iterRow));
        x += ITERATION_STEP;
    }

    return iterationCount;
}
