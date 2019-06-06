// Copyright 2019 Shemetov Philip

#include <gtest/gtest.h>
#include <string>

#include "../include/algorithm_sort_station.h"

TEST(Test_AlgSortStation, Default_Constructor_Test) {
    // Arrange

    // Act

    // Assert
    ASSERT_NO_THROW(AlgSortStation(25));
}

TEST(Test_AlgSortStation, Cant_Create_Stack_With_Negative_Length) {
    // Arrange

    // Act

    // Assert
    ASSERT_ANY_THROW(AlgSortStation(-1));
}

TEST(Test_AlgSortStation, Test_Copy_Constructor) {
    // Arrange
    AlgSortStation first(3);
    AlgSortStation second(4);
    // Act
    first = second;

    // Assert
    EXPECT_EQ(first.GetSize(), second.GetSize());
}

TEST(Test_AlgSortStation, Copied_Stack_Is_Equal_To_Source_One) {
    // Arrange
    AlgSortStation first(3);

    // Act
    first.Put(4);
    AlgSortStation second(first);

    // Assert
    EXPECT_EQ(first.Get(), second.Get());
}

TEST(Test_AlgSortStation, Can_Stack_Get_Its_Size) {
    // Arrange
    AlgSortStation first(3);

    // Act
    first.Put(4);

    // Assert
    EXPECT_EQ(3, first.GetSize());
}

TEST(Test_AlgSortStation, Put_Throws_When_Stack_Is_Full) {
    // Arrange
    AlgSortStation first(2);

    // Act
    first.Put(10);
    first.Put(20);

    // Assert
    ASSERT_ANY_THROW(first.Put(100));
}

TEST(Test_AlgSortStation, Can_Get_And_Set_Element) {
    // Arrange
    AlgSortStation first(3);

    // Act
    first.Put(4);

    // Assert
    EXPECT_EQ(4, first.Get());
}

TEST(Test_AlgSortStation, Cant_Get_Element_From_Empty_Stack) {
    // Arrange
    AlgSortStation first(4);

    // Act

    // Assert
    ASSERT_ANY_THROW(first.Get());
}

TEST(Test_AlgSortStation, Cant_Get_Elment_From_Stack_Without_Mem) {
    // Arrange
    AlgSortStation first(0);

    // Act

    // Assert
    ASSERT_ANY_THROW(first.Get());
}

TEST(Test_AlgSortStation, Can_Pop_Element) {
    // Arrange
    AlgSortStation first(5);

    // Act
    first.Put(2);
    first.Put(3);
    first.Put(10);
    first.Pop();

    // Assert
    EXPECT_NE(10, first.Get());
}

TEST(Test_AlgSortStation, Cant_Pop_Elment_From_Stack_Without_Mem) {
    // Arrange
    AlgSortStation first(0);

    // Act

    // Assert
    ASSERT_ANY_THROW(first.Pop());
}

TEST(Test_AlgSortStation, Pop_Throws_When_Stack_Is_Full) {
    // Arrange
    AlgSortStation first(3);

    // Act

    // Assert
    ASSERT_ANY_THROW(first.Pop());
}

TEST(Test_AlgSortStation, Cant_Get_Pop_From_Empty_Stack) {
    // Arrange
    AlgSortStation first(4);

    // Act

    // Assert
    ASSERT_ANY_THROW(first.Pop());
}

TEST(Test_AlgSortStation, Can_Detect_If_Stack_Is_Not_Empty) {
    // Arrange
    AlgSortStation first(3);

    // Act
    first.Put(11);

    // Assert
    EXPECT_EQ(0, first.IsEmpty());
}

TEST(Test_AlgSortStation, Can_Detect_If_Stack_Is_Empty) {
    // Arrange
    AlgSortStation first(3);

    // Act

    // Assert
    EXPECT_EQ(1, first.IsEmpty());
}

TEST(Test_AlgSortStation, Can_Detect_If_Stack_Is_Not_Full) {
    // Arrange
    AlgSortStation first(3);

    // Act
    first.Put(11);

    // Assert
    EXPECT_EQ(0, first.IsFull());
}

TEST(Test_AlgSortStation, Can_Detect_If_Stack_Is_Full) {
    // Arrange
    AlgSortStation first(1);

    // Act
    first.Put(10);

    // Assert
    EXPECT_EQ(1, first.IsFull());
}

TEST(Test_AlgSortStation, Stack_Is_Valid) {
    // Arrange
    AlgSortStation first(3);

    // Act

    // Assert
    ASSERT_ANY_THROW(first.Pop());
}
