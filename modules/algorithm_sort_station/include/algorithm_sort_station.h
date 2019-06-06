// Copyright 2019 Shemetov Philipp

#ifndef MODULES_ALGORITHM_SORT_STATION_INCLUDE_ALGORITHM_SORT_STATION_H_
#define MODULES_ALGORITHM_SORT_STATION_INCLUDE_ALGORITHM_SORT_STATION_H_

#include <string>
const int DefMemSize = 25;

#pragma once

class AlgSortStation {
 private:
  int top;
  int DataCount;
  int MemSize;
  int *pMem;

 public:
  explicit AlgSortStation(int len = DefMemSize);
  AlgSortStation(const AlgSortStation &obj);
  ~AlgSortStation() { pMem = NULL; }
  int GetSize() { return MemSize; }
  void Put(const int &elem);
  int Get();
  void Pop();
  bool IsEmpty() const { return top == -1; }
  bool IsFull() const { return top == MemSize - 1; }
};
#endif  // MODULES_ALGORITHM_SORT_STATION_INCLUDE_ALGORITHM_SORT_STATION_H_
