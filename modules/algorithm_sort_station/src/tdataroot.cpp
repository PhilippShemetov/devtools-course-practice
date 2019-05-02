#include <stdio.h>
#include "include/tdataroot.h"

TDataRoot::TDataRoot(int Size) : TDataCom()
{
	if (Size < 0)
		throw "Wrong size";
	DataCount = 0;
	MemSize = Size;
	if (Size == 0)
	{
		pMem = NULL;
		MemType = MEM_RENTER;
	}
	else
	{
		pMem = new TElem[MemSize];
		MemType = MEM_HOLDER;
	}
}

TDataRoot::~TDataRoot()
{
	if (MemType == MEM_HOLDER)
		delete[] pMem;
	pMem = NULL;
}

void TDataRoot::SetMem(void *p, int Size)
{
	if (MemType == MEM_HOLDER)
		delete[] pMem;
	pMem = (TElem *)p;
	MemType = MEM_RENTER;
	MemSize = Size;
}

bool TDataRoot::IsEmpty(void) const
{
	return DataCount == 0;
}

bool TDataRoot::IsFull(void) const
{
	return DataCount == MemSize;
}
