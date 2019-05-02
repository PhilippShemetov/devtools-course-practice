#include <string>
const int MaxLen = 255;

class TFormula
{
private:
  char Formula[MaxLen];
  char PostfixForm[MaxLen];
  int lenghtFormula;
  int lenghtPostfixForm;

public:
  TFormula(char *form);
  TFormula(std::string form);
  int FormulaChecker(int Brackets[], int size);
  int FormulaConverter();
  double FormulaCalculator();
};
int PriorityOper(char sign);
