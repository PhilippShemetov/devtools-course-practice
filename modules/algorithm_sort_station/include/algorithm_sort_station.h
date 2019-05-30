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
  AlgSortStation(int len);
  AlgSortStation(const AlgSortStation &obj);
  ~AlgSortStation(){};
  int GetSize() { return MemSize; }
  void Put(const int &elem);
  int Get();
  void Resize(int newLen);
  void Pop();
  bool IsEmpty() const { return top == -1; }
  bool IsFull() const { return top == MemSize - 1; }
  int IsValid();
  void Print();
};
