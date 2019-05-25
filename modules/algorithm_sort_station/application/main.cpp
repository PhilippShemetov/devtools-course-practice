#include <string>
#include "tstack.h"

int main()
{
    std::string formula = "( 5 + 7 ) * 4";
    std::string postfixf;
    int result;
    TStack stack;
    stack.Put(46);
    stack.Put(67);
    stack.Print();
    return 0;
}