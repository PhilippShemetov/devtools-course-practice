#include <string>

#pragma once


class AlgSortStation
{
protected:
  int top;
  int *mem;
  int DataCount;
  int MemSize;
  int *pMem;


public:
  AlgSortStation();
  AlgSortStation(const AlgSortStation &obj);
  ~AlgSortStation(){};
  int GetSize() { return MemSize; }
  void Put(const int &elem);
  int Get();
  void Pop();
  void Resize(int newLen);
  bool IsEmpty() const { return top == -1; }
  bool IsFull() const { return top == MemSize - 1; }
  int IsValid();
  void Print();
};

int PriorityOper(char sign);
