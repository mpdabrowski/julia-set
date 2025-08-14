#include <iostream>
#include <complex>
#include <bits/stdc++.h>
#include <cmath>
#include "Bitmap.h"

const std::complex<double> c(-0.79, 0.15);

std::complex<double> f(std::complex<double> z) {
    return (z * z) + c;
}

int main() {
    int numOfIterations = 100;

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
            y += 0.01;
        }
        points.push_back(row);
        iterationCount.push_back(iterRow);
        x += 0.01;
    }

    while(numOfIterations > 0) {
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points[i].size(); j++) {
                std::complex<double> z = f(points[i][j]);
                if (abs(z) > 2) {
                    if (iterationCount[i][j] == -1) {
                        iterationCount[i][j] = 100 - numOfIterations;
                    }
                    continue;
                }
                points[i][j] = z;
            }
        }
        --numOfIterations;
    }

    Bitmap::drawBitmap(iterationCount);



    // for (int i = 0; i < iterationCount.size(); i++) {
    //     for (int j = 0; j < iterationCount[i].size(); j++) {
    //         int z = iterationCount[i][j];
    //         if(z == -1) {
    //             std::cout << "#";
    //         } else if (z > 450) {
    //             std::cout << ".";
    //         } else if (z > 400) {
    //             std::cout << "*";
    //         } else {
    //              std::cout << " ";
    //         }
    //     }
    //     std::cout << std::endl;
    // }


    return 0;
}
