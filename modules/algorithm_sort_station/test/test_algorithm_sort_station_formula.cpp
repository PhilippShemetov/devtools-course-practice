#include <gtest/gtest.h>
#include <string>

#include "../include/algorithm_sort_station_formula.h"

TEST(Test_AlgSortStation_Formula, Can_Check_Proper_Formula)
{
    // Arrange
    std::string str1 = "(2+3)*6*4/8-(2+5)/16";
    int size = str1.length() * 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    EXPECT_EQ(0, first.FormulaChecker(brackets, size));
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula, Can_Check_Wrong_Formula)
{
    // Arrange
    std::string str1 = "(2+3)*6*4/8-(2+5)/16))";
    int size = str1.length() * 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    EXPECT_EQ(2, first.FormulaChecker(brackets, size));
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula, Can_Calculate_Proper_Formula)
{
    // Arrange
    std::string str1 = "(2+3)*6*4/8-(2+5)/16";
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    EXPECT_EQ(0, first.FormulaConverter());
}

TEST(Test_AlgSortStation_Formula, Throw_When_Calculate_Wrong_Formula)
{
    // Arrange
    std::string str1 = "))(2+3)*6*4/8-(2+5)/16";
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    ASSERT_ANY_THROW(first.FormulaCalculator());
}

TEST(Test_AlgSortStation_Formula, Throw_When_Create_Empty_Formula)
{
    // Arrange
    std::string str1 = "";
    // Act

    // Assert
    ASSERT_ANY_THROW(AlgSortStationFormula first((char *)str1.c_str()));
}