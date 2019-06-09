// Copyright 2019 Shemetov Philip

#include <gtest/gtest.h>
#include <string>

#include "../include/alg_sort_station_formula.h"


TEST(Test_AlgSortStation_Formula, Default_Constructor_Test) {
    // Arrange
    std::string str1 = "(2+3)*6*4/8-(2+5)/16";
    // Act

    // Assert
    ASSERT_NO_THROW(AlgSortStationFormula first(str1));
}

TEST(Test_AlgSortStation_Formula, Throw_When_Create_Empty_Formula) {
    // Arrange
    std::string str1 = "";
    // Act

    // Assert
    ASSERT_ANY_THROW(AlgSortStationFormula first(str1));
}


TEST(Test_AlgSortStation_Formula, Can_Check_Proper_Formula) {
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

TEST(Test_AlgSortStation_Formula, Can_Check_Wrong_Formula) {
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

TEST(Test_AlgSortStation_Formula, Can_Check_Formula_On_Throw) {
    // Arrange
    std::string str1 = "(2+3)*6*4/8-(2+5)/16";
    int size = 1;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    ASSERT_ANY_THROW(first.FormulaChecker(brackets, size));
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula, Can_Calculate_Proper_Formula) {
    // Arrange
    std::string str1 = "(2+3)*6*4/8-(2+5)/16";
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    EXPECT_EQ(0, first.FormulaConverter());
}

TEST(Test_AlgSortStation_Formula, Can_Calcualte_Formula) {
    // Arrange
    std::string str1 = "7+(3*10)-2";
    int size = str1.length() * 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act
    // Assert
    EXPECT_EQ(35, first.FormulaCalculator());
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula, Throw_When_Calculate_Wrong_Formula) {
    // Arrange
    std::string str1 = "))(2+3)*6*4/8-(2+5)/16";
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    ASSERT_ANY_THROW(first.FormulaCalculator());
}


TEST(Test_AlgSortStation_Formula, Check_Return_Of_Function_Priority_Oper) {
    // Arrange
    char first = '(';
    // Act

    // Assert
    EXPECT_EQ(0, PriorityOper(first));
}

TEST(Test_AlgSortStation_Formula, Check_Return_Of_Function_Priority_Oper_1) {
    // Arrange
    char first = ')';
    // Act

    // Assert
    EXPECT_EQ(1, PriorityOper(first));
}

TEST(Test_AlgSortStation_Formula,
    Check_Throw_Error_Of_Function_Priority_Oper) {
    // Arrange
    char first = '{';
    // Act

    // Assert
    ASSERT_ANY_THROW(PriorityOper(first));
}


