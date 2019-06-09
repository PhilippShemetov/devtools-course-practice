// Copyright 2019 Shemetov Philipp

#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include "../include/area_figures_application.h"

std::string AreaFiguresApplication::operator()(int argc, const char **argv) {
    std::string output = "area = ";
    if (argc == 1) {
        return Help();
    }
    try {
        output += ParseCommand(argc, argv);
    }
    catch (std::runtime_error &exp) {
        return exp.what();
    }
    catch(std::string &exp) {
        return exp;
    }
    return output;
}

double AreaFiguresApplication::ParseDouble(const char *arg) {
    char *end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string AreaFiguresApplication::Help() {
    return "AreaFigures class application:\n"
           "Commands:\n"
           "help - print help information\n"
           "calc <parameter> calculate area of figures, "
           "shapes you can shoose using parameters\n"
           "Parameters listed below:\n"
           "rectangle - choose rectangle\n"
           "square - choose square\n"
           "rhombus - choose cylinder\n"
           "equil triangle - choose equil triangle\n"
           "circle - choose circle\n"
           "right triangle - choose tetrahedron\n"
           "arguments for shapes:\n"
           "square - <length> \n"
           "rhombus - <side> <height>\n"
           "equil triangle - <height> <side>\n"
           "circle - <radius>\n"
           "right triangle - <sideA> <sideB>\n"
           "rectangle - <length> <width>\n";
}

std::string AreaFiguresApplication::ParseCommand(int argc, const char **arg) {
    if (strcmp(arg[1], "help") == 0) {
        return Help();
    } else if (strcmp(arg[1], "calc") == 0) {
        return ParseParams(argc, arg);
    } else {
        throw std::runtime_error("wrong command");
    }
}

std::string AreaFiguresApplication::ParseParams(int argc, const char **argv) {
    if (strcmp(argv[2], "rectangle") == 0) {
        if (argc < 5)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(AreaFigures::RectangleArea(arg1,arg2));
    } else if (strcmp(argv[2], "square") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(AreaFigures::SquareArea(arg1));
    } else if (strcmp(argv[2], "rhombus") == 0) {
        if (argc < 5)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(AreaFigures::RhombusArea(arg1, arg2));
    } else if (strcmp(argv[2], "equil triangle") == 0) {
        if (argc < 6)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(AreaFigures::EquilTriangleArea(arg1, arg2));
    } else if (strcmp(argv[2], "circle") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        return std::to_string(AreaFigures::CircleArea(arg1));
    } else if (strcmp(argv[2], "right triangle") == 0) {
        if (argc < 4)
            throw std::runtime_error("too few arguments");
        double arg1 = ParseDouble(argv[3]);
        double arg2 = ParseDouble(argv[4]);
        return std::to_string(AreaFigures::RightTriangleArea(arg1,arg2));
    } else {
        throw std::runtime_error("wrong param");
    }
}