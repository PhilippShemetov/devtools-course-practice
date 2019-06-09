// Copyright 2019 Shemetov Philipp

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <iostream>
#include "../include/alg_sort_station_formula.h"
#include "../include/algorithm_sort_station.h"


AlgSortStationFormula::AlgSortStationFormula(std::string form) {
    lenghtFormula = form.length();
    lenghtPostfixForm = 0;
    if (lenghtFormula != 0) {
        snprintf(Formula, MaxLen, "%s",
        reinterpret_cast<char const *>(form.c_str()));
        snprintf(PostfixForm, MaxLen, "%s", "");
    } else {
        throw "Formula is empty!";
    }
}

int AlgSortStationFormula::FormulaChecker(int Brackets[], int size) {
    AlgSortStation st(lenghtFormula);
    int index = 0;
    int errCounter = 0;
    for (int i = 0; i < lenghtFormula; i++) {
        if (!((Formula[i] == '(') || (Formula[i] == ')')))
            continue;
        if (Formula[i] == '(') {
            st.Put(i);
        }
        if (Formula[i] == ')') {
            if (!st.IsEmpty()) {
                if (index + 2 < size) {
                    Brackets[index++] = st.Get();
                    Brackets[index++] = i;
                    st.Pop();
                } else {
                    throw "Brackets_index_out_range,need more memory";
                }
            } else {
                if (index + 1 < size) {
                    Brackets[index++] = 0;
                    errCounter++;
                } else {
                    throw "Brackets_index_out_range,need more memory";
                }
            }
        }
    }
    while (!st.IsEmpty()) {
        if (index + 2 < size) {
            errCounter++;
            Brackets[index++] = st.Get();
            Brackets[index++] = 0;
            st.Pop();
        } else {
            throw "Brackets_index_out_range,need more memory";
        }
    }
    std::cout << "Amount of Error = " << errCounter << std::endl;
    std::cout << "Open Bracket | Close Bracket" << std::endl;
    for (int i = 0; i < index; i++) {
        if (i % 2 == 0)
            std::cout << "\t    " << Brackets[i] << "|";
        else
            std::cout << Brackets[i] << std::endl;
    }

    return errCounter;
}

int AlgSortStationFormula::FormulaConverter() {
    int indexPostfix = 0;
    int *brackets = new int[lenghtFormula * 2];
    if (FormulaChecker(brackets, lenghtFormula * 2) != 0)
        throw "wrong Formula!";
    AlgSortStation st(lenghtFormula);
    for (int i = 0; i < lenghtFormula; i++) {
        if (isdigit(Formula[i])) {
            if (indexPostfix != 0) {
                if (isdigit(PostfixForm[indexPostfix - 1]))
                    PostfixForm[indexPostfix++] = ' ';
            }
            for (; (i < 20) && isdigit(Formula[i]); i++)
                PostfixForm[indexPostfix++] = Formula[i];
        }
        if (Formula[i] == '+' || Formula[i] == '-' ||
            Formula[i] == '*' || Formula[i] == '/' ||
            Formula[i] == '(' || Formula[i] == ')') {
            if (st.IsEmpty()) {
                st.Put(Formula[i]);
            } else if (Formula[i] == '(') {
                st.Put(Formula[i]);
            } else if (Formula[i] == ')') {
                while (PriorityOper(st.Get()) != PriorityOper('(')) {
                    PostfixForm[indexPostfix++] = st.Get();
                    st.Pop();
                }
                if (PriorityOper(st.Get()) == PriorityOper('('))
                    st.Pop();
            } else if (PriorityOper(Formula[i]) > PriorityOper(st.Get())) {
                st.Put(Formula[i]);
            } else {
                while ((!st.IsEmpty()) && (PriorityOper(Formula[i])
                <= PriorityOper(st.Get()))) {
                    PostfixForm[indexPostfix++] = st.Get();
                    st.Pop();
                }
                st.Put(Formula[i]);
            }
        }
    }
    while (!st.IsEmpty()) {
        PostfixForm[indexPostfix++] = st.Get();
        st.Pop();
    }
    lenghtPostfixForm = indexPostfix;
    delete[] brackets;
    return 0;
}

double AlgSortStationFormula::FormulaCalculator() {
    if (lenghtPostfixForm == 0)
        FormulaConverter();
    AlgSortStation st(lenghtPostfixForm);
    int oper1 = 0, oper2 = 0;
    int chislo = 0;
    int coefRank = -10;
    for (int i = 0; i < lenghtPostfixForm; i++) {
        bool flagLoopDigit = false;
        while ((i < lenghtFormula) && (isdigit(PostfixForm[i]))) {
            coefRank += 10;
            chislo *= coefRank;
            chislo += PostfixForm[i] - '0';
            i++;
            flagLoopDigit = true;
        }
        if (flagLoopDigit) {
            st.Put(chislo);
            chislo = 0;
            coefRank = -10;
        }
        if (PostfixForm[i] == '+') {
            oper2 = st.Get();
            st.Pop();
            oper1 = st.Get();
            st.Pop();
            st.Put(oper1 + oper2);
        } else if (PostfixForm[i] == '-') {
            oper2 = st.Get();
            st.Pop();
            oper1 = st.Get();
            st.Pop();
            st.Put(oper1 - oper2);
        } else if (PostfixForm[i] == '*') {
            oper2 = st.Get();
            st.Pop();
            oper1 = st.Get();
            st.Pop();
            st.Put(oper1 * oper2);
        } else if (PostfixForm[i] == '/') {
            oper2 = st.Get();
            if (oper2 == 0)
                throw "devide by zero";
            st.Pop();
            oper1 = st.Get();
            st.Pop();
            st.Put(oper1 / oper2);
        }
    }
    return st.Get();
}

int PriorityOper(char sign) {
    switch (sign) {
    case '(':
        return 0;
        break;
    case ')':
        return 1;
        break;
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 3;
        break;
    default:
        throw "Out of range";
        break;
    }
}
