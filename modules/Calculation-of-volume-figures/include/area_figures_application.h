// Copyright 2019 Shemetov Philipp

#ifndef MODULES_CALCULATION_OF_VOLUME_FIGURES_INCLUDE_AREA_FIGURES_APPLICATION_H_
#define MODULES_CALCULATION_OF_VOLUME_FIGURES_INCLUDE_AREA_FIGURES_APPLICATION_H_

#include <string>
#include "include/area_figures.h"

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

#endif  // MODULES_CALCULATION_OF_VOLUME_FIGURES_INCLUDE_AREA_FIGURES_APPLICATION_H_
