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

TEST(Test_AlgSortStation_Formula,
    Can_Check_Formula_On_Throw_If_Have_Brackets_Beginnig) {
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

TEST(Test_AlgSortStation_Formula,
    Can_Check_Formula_On_Throw_If_Doesnt_Have_Open_Brackets_Beginning) {
    // Arrange
    std::string str1 = "5*)4+3";
    int size = 1;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    ASSERT_ANY_THROW(first.FormulaChecker(brackets, size));
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula,
    Can_Check_Formula_On_Throw_If_Doesnt_Have_Closed_Brackets_Beginning) {
    // Arrange
    std::string str1 = "5*(4+3";
    int size = 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    ASSERT_ANY_THROW(first.FormulaChecker(brackets, size));
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula, Can_Check_Formula_With_Open_Brackets) {
    // Arrange
    std::string str1 = "5*(4+3";
    int size = str1.length() * 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act

    // Assert
    EXPECT_EQ(1, first.FormulaChecker(brackets, size));
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
    std::string str1 = "(7+(3*10)-2)/5";
    int size = str1.length() * 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act
    // Assert
    EXPECT_EQ(7, first.FormulaCalculator());
    delete[] brackets;
}

TEST(Test_AlgSortStation_Formula, Devided_By_Zero) {
    // Arrange
    std::string str1 = "(7+(3*10)-2)/0";
    int size = str1.length() * 2;
    int *brackets = new int[size];
    AlgSortStationFormula first(str1);
    // Act
    // Assert
    ASSERT_ANY_THROW(first.FormulaCalculator());
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


