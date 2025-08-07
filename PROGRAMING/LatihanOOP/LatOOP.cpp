#include <iostream>
#include <cmath>
#include "LatOOP.h"

double LatOOP::hmax(double kecepatan, double elevasi)
{
    double sudut = elevasi * 3.14 / 180;
    double sinkos = sin(sudut);

    double hasil = (kecepatan * kecepatan * (sinkos * sinkos)) / (10 * 2);
    return hasil;
}

double LatOOP::xmax(double kecepatan, double elevasi)
{
    double sudut = elevasi * 3.14 / 180;
    double sinkos = sin(sudut);

    double hasil = (kecepatan * kecepatan * (sinkos * 2)) / 10;
    return hasil;
}
