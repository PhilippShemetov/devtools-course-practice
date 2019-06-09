// Copyright 2019 Sazanov Dima

#include <gtest/gtest.h>

#include "include/area_figures.h"

TEST(Sazanov_Dima_AreaFigure, Can_Calculate_Circle_Area) {
        // Arrange
        double radius = 2.0;
        // Act
        double result = AreaFigures::CircleArea(radius);
        // Assert
        double exp_ans = 12.56;
        EXPECT_NEAR(exp_ans, result, 0.01);
}

TEST(Sazanov_Dima_AreaFigure, Can_Calculate_Rhombus_Area) {
        // Arrange
        double side = 5.0;
        double height = 2.0;
        // Act
        double result = AreaFigures::RhombusArea(side, height);
        // Assert
        double exp_ans = 10.00;
        EXPECT_EQ(exp_ans, result);
}

TEST(Sazanov_Dima_AreaFigure, Can_Calculate_Square_Area) {
        // Arrange
        double length = 3.0;
        // Act
        double result = AreaFigures::SquareArea(length);
        // Assert
        double exp_ans = 9.0;
        EXPECT_EQ(exp_ans, result);
}

TEST(Sazanov_Dima_AreaFigure, Can_Calculate_Rectangle_Area) {
        // Arrange
        double length = 3.0;
        double width = 2.0;
        // Act
        double result = AreaFigures::RectangleArea(length, width);
        // Assert
        double exp_ans = 6.0;
        EXPECT_EQ(exp_ans, result);
}

TEST(Sazanov_Dima_AreaFigure, Can_Calculate_EquilTriangle_Area) {
        // Arrange
        double height = 5.0;
        double side = 10.0;
        // Act
        double result = AreaFigures::EquilTriangleArea(height, side);
        // Assert
        double exp_ans = 25.0;
        EXPECT_EQ(exp_ans, result);
}

TEST(Sazanov_Dima_AreaFigure, Can_Calculate_RightTriangle_Area) {
        // Arrange
        double sideA = 5.0;
        double sideB = 6.0;
        // Act
        double result = AreaFigures::RightTriangleArea(sideA, sideB);
        // Assert
        double exp_ans = 15.00;
        EXPECT_EQ(exp_ans, result);
}
