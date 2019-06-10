// Copyright 2019 Sazanov Dima

#ifndef MODULES_CALCULATION_OF_VOLUME_FIGURES_INCLUDE_AREA_FIGURES_H_
#define MODULES_CALCULATION_OF_VOLUME_FIGURES_INCLUDE_AREA_FIGURES_H_

class AreaFigures {
 public:
        static double CircleArea(double radius);
        static double RhombusArea(double side, double height);
        static double SquareArea(double length);
        static double RectangleArea(double length, double width);
        static double EquilTriangleArea(double height, double side);
        static double RightTriangleArea(double sideA, double sideB);
};

#endif  // MODULES_CALCULATION_OF_VOLUME_FIGURES_INCLUDE_AREA_FIGURES_H_
