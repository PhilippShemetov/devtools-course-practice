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

public:
  TStack();
  TStack(const TStack &obj);
  ~TStack(){};
  void SetMem(int Size);
  int GetSize() { return MemSize; }
  void Put(const int &elem);
  int Get();
  void Pop();
  void Resize(int newLen);
  bool IsEmpty() const { return top == -1; }
  bool IsFull() const { return top == MemSize - 1; }
  virtual int IsValid();
  virtual void Print();
};

int PriorityOper(char sign);
