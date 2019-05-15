#include <string>
#include "../include/tstack.h"

int main()
{
    std::string formula = "( 5 + 7 ) * 4";
    std::string postfixf;
    int result;
    TStack stack;
    stack.Put(formula[0]);

    return 0;
}