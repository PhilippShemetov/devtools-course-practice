// Copyright 2019 Shemetov Philipp

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "../include/area_figures_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;
class AreaFiguresApplicationTest :public::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("area-figures");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
                    ::testing::internal::RE(expected)));
    }
 private:
    AreaFiguresApplication app_;
    std::string output_;
};

TEST_F(AreaFiguresApplicationTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("AreaFigures class application:");
}

TEST_F(AreaFiguresApplicationTest, Do_Print_Help_With_Arguments) {
    std::vector<std::string> args = {"help"};

    Act(args);

    Assert("AreaFigures class application:");
}

TEST_F(AreaFiguresApplicationTest, Check_Number_Of_Arguments_Rectangle) {
    vector<string> args = {"calc", "rectangle"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(AreaFiguresApplicationTest, Check_Number_Of_Arguments_Square) {
    vector<string> args = {"calc", "square"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(AreaFiguresApplicationTest, Check_Number_Of_Arguments_Rhombus) {
    vector<string> args = {"calc", "rhombus"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(AreaFiguresApplicationTest, Check_Number_Of_Arguments_Equil_Triangle) {
    vector<string> args = {"calc", "equil triangle"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(AreaFiguresApplicationTest, Check_Number_Of_Arguments_Circle) {
    vector<string> args = {"calc", "circle"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(AreaFiguresApplicationTest, Check_Number_Of_Arguments_Right_Triangle) {
    vector<string> args = {"calc", "right triangle"};

    Act(args);

    Assert("too few arguments");
}

TEST_F(AreaFiguresApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"calc", "rhombus", "2", "pu"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Detect_Wrong_Param) {
    vector<string> args = {"calc", "nst", "2", "4", "5"};

    Act(args);

    Assert("wrong param.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Detect_Wrong_Command) {
    vector<string> args = {"fs", "rectangle", "2", "4"};

    Act(args);

    Assert("wrong command.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Calculate_Rectangle_Area) {
    vector<string> args = {"calc", "rectangle", "2", "3"};

    Act(args);

    Assert("area = 6.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Calculate_Circle_Area) {
    vector<string> args = {"calc", "circle", "3"};

    Act(args);

    Assert("area = 28.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Calculate_Square_Area) {
    vector<string> args = {"calc", "square", "4"};

    Act(args);

    Assert("area = 16.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Calculate_Rhombus_Area) {
    vector<string> args = {"calc", "rhombus", "10", "2"};

    Act(args);

    Assert("area = 20.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Calculate_Equil_Triangle_Area) {
    vector<string> args = {"calc", "equil triangle", "5", "2"};

    Act(args);

    Assert("area = 5.*");
}

TEST_F(AreaFiguresApplicationTest, Can_Calculate_Right_Triangle_Area) {
    vector<string> args = {"calc", "right triangle", "5", "6"};

    Act(args);

    Assert("area = 15.*");
}