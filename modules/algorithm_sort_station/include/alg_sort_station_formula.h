// Copyright 2019 Shemetov Philipp

#ifndef MODULES_ALG_SORT_STATION_INCLUDE_ALG_SORT_STATION_FORMULA_H_
#define MODULES_ALG_SORT_STATION_INCLUDE_ALG_SORT_STATION_FORMULA_H_

#include <string>
const int MaxLen = 255;

class AlgSortStationFormula {
 private:
    char Formula[MaxLen];
    char PostfixForm[MaxLen];
    int lenghtFormula;
    int lenghtPostfixForm;

 public:
    explicit AlgSortStationFormula(char *form);
    explicit AlgSortStationFormula(std::string form);
    int FormulaChecker(int Brackets[], int size);
    int FormulaConverter();
    double FormulaCalculator();
};
int PriorityOper(char sign);

#endif  // MODULES_ALG_SORT_STATION_INCLUDE_ALG_SORT_STATION_FORMULA_H_
