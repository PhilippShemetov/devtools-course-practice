// Copyright 2019 Sazanov Dima

#define _USE_MATH_DEFINES
#include <cmath>

#include "include/area_figures.h"

double AreaFigures::CircleArea(double radius) {
        return M_PI * pow(radius, 2.0);
}

double AreaFigures::RhombusArea(double side, double height) {
        return side * height;
}

double AreaFigures::SquareArea(double length) {
        return pow(length, 2.0);
}

double AreaFigures::RectangleArea(double length, double width) {
        return length * width;
}

double AreaFigures::EquilTriangleArea(double height, double side) {
        return (height * side) / 2;
}

double AreaFigures::RightTriangleArea(double sideA, double sideB) {
        return (sideA * sideB) / 2;
}
