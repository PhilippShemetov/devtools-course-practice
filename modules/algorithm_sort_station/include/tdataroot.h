
#ifndef __DATAROOT_H__
#define __DATAROOT_H__

#include "tdatacom.h"

#define DefMemSize 25

#define DataEmpty -101
#define DataFull -102
#define DataNoMem -103

typedef int TElem;
typedef TElem *PTElem;
typedef int TData;

enum TMemType
{
  MEM_HOLDER,
  MEM_RENTER
};

class TDataRoot : public TDataCom
{
protected:
  PTElem pMem;
  int MemSize;
  int DataCount;
  TMemType MemType;

  void SetMem(void *p, int Size);

public:
  virtual ~TDataRoot();
  TDataRoot(int Size = DefMemSize);
  virtual bool IsEmpty(void) const;
  virtual bool IsFull(void) const;
  virtual void Put(const TData &Val) = 0;
  virtual TData Get(void) = 0;
  virtual int IsValid() = 0;
  virtual void Print() = 0;
  friend class TMultiStack;
  friend class TSuperMultiStack;
  friend class TComplexMultiStack;
};

#endif
