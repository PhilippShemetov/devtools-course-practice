// Copyright 2019 Shemetov Philipp

#include <iostream>
#include <algorithm>
#include "../include/algorithm_sort_station.h"

AlgSortStation::AlgSortStation(int len) {
    if (len < 0)
        throw "Wrong Size";
    DataCount = 0;
    MemSize = len;
    pMem = new int[MemSize];
    top = -1;
    for (int i = 0; i < MemSize; i++)
        pMem[i] = 0;
}

AlgSortStation::AlgSortStation(const AlgSortStation& obj) {
    DataCount = obj.DataCount;
    MemSize = obj.MemSize;
    top = obj.top;
    pMem = new int[MemSize];
    std::copy(obj.pMem, obj.pMem + MemSize, pMem);
}

void AlgSortStation::Put(const int &elem) {
    if (!IsFull()) {
        pMem[++top] = elem;
        DataCount++;
    } else {
        throw "Stack is full";
    }
}

void AlgSortStation::Pop() {
    if (!IsEmpty()) {
        top--;
        DataCount--;
    } else {
        throw "Stack is empty";
    }
}

int AlgSortStation::Get() {
    if (!IsEmpty()) {
        return pMem[top];
    } else {
        throw "Stack is empty";
    }
}
