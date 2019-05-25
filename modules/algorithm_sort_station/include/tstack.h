#include <string>

#pragma once



enum TMemType
{
  MEM_HOLDER,
  MEM_RENTER
};

class TStack
{
protected:
  int top;
  int *mem;
  int DataCount;
  int MemSize;
  int *pMem;
  void SetMem(int Size);

public:
  TStack();
  TStack(const TStack &obj);
  ~TStack(){};
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
