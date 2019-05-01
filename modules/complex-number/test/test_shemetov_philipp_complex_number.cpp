// Copyright 2019 Shemetov Philipp

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shemetov_Philipp_ComplexNumberTest, Can_Difference_Six_Complex_Numbers) {
    // Act
    ComplexNumber a(20., 20.);
    ComplexNumber b(3., 3.);
    ComplexNumber expect(5., 5.);
    ComplexNumber c = a - b - b - b - b - b;

     // Assert
    EXPECT_EQ(expect.getRe(), c.getRe());
    EXPECT_EQ(expect.getIm(), c.getIm());
}

TEST(Shemetov_Philipp_ComplexNumberTest, Can_Add_Complex_Four) {
    // Arrange
    ComplexNumber first(2.0, 9.0);
    ComplexNumber second(3.0, 11.0);
    ComplexNumber third(4.0, 14.0);
    ComplexNumber fourth(5.0, 14.0);

    // Act
    ComplexNumber a = first + second + third + fourth;

    // Assert
    ComplexNumber expected_a(14.0, 48.0);
    EXPECT_EQ(expected_a, a);
}

TEST(Shemetov_Philipp_ComplexNumberTest,
    Multiplication_By_Imaginary_One_Works_Incorrectly) {
    // Arrange
    double d1 = 7.1;
    double d2 = 54.3;
    ComplexNumber a(d1, d2);
    ComplexNumber b(-d2, d1);
    ComplexNumber c(1.8, 1.3);

    // Act
    ComplexNumber e = b * c;

     // Assert
    EXPECT_TRUE(b != e);
}

TEST(Shemetov_Philipp_ComplexNumberTest, Can_Create_Negative_Real) {
    // Arrange
    double re = -3.98;
    double im = 1.0;

    // Act
    ComplexNumber a(re, im);

    // Assert
    EXPECT_EQ(re, a.getRe());
    EXPECT_EQ(im, a.getIm());
}