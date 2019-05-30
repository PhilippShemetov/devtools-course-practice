// Copyright 2019 Shemetov Philipp

#ifndef MODULES_ALGORITHM_SORT_STATION_INCLUDE_ALGORITHM_SORT_STATION_H_
#define MODULES_ALGORITHM_SORT_STATION_INCLUDE_ALGORITHM_SORT_STATION_H_

#include <string>

#pragma once

class AlgSortStation {
 protected:
  int top;
  int DataCount;
  int MemSize;
  int *pMem;

 public:
  explicit AlgSortStation(int len);
  AlgSortStation(const AlgSortStation &obj);
  ~AlgSortStation() {}
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
#endif  // MODULES_ALGORITHM_SORT_STATION_INCLUDE_ALGORITHM_SORT_STATION_H_
