// Copyright 2019 Shemetov Philipp

#ifndef MODULES_AREA_FIGURES_INCLUDE_AREA_FIGURES_APPLICATION_H_
#define MODULES_AREA_FIGURES_INCLUDE_AREA_FIGURES_APPLICATION_H_

#include <string>
#include "area_figures.h"

class AreaFiguresApplication {
 private:
    std::string ParseCommand(int argc, const char** argv);
    std::string ParseParams(int argc, const char** arg);
    double ParseDouble(const char* arg);
 public:
    std::string Help();
    AreaFiguresApplication() = default;
    std::string operator()(int argc, const char **argv);
};

#endif  // MODULES_AREA_FIGURES_INCLUDE_AREA_FIGURES_APPLICATION_H_