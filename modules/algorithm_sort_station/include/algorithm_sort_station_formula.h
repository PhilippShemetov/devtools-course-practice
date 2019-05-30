#include <string>
const int MaxLen = 255;

class AlgSortStationFormula
{
private:
    char Formula[MaxLen];
    char PostfixForm[MaxLen];
    int lenghtFormula;
    int lenghtPostfixForm;

public:
    AlgSortStationFormula(char *form);
    AlgSortStationFormula(std::string form);
    int FormulaChecker(int Brackets[], int size);
    int FormulaConverter();
    double FormulaCalculator();
};
int PriorityOper(char sign);
