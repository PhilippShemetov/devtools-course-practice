// Copyright 2019 Shemetov Philipp

#include <iostream>
#include "../include/algorithm_sort_station.h"

AlgSortStation::AlgSortStation(int len)
{
	if (len < 0)
		throw "Wrong size";
	DataCount = 0;
	MemSize = len;
	pMem = new int[MemSize];
	top = -1;
	for (int i = 0; i < MemSize; i++)
		pMem[i] = 0;
}
AlgSortStation::AlgSortStation(const AlgSortStation &obj)
{
	DataCount = obj.DataCount;
	MemSize = obj.MemSize;
	top = obj.top;
	pMem = new int[MemSize];
	std::copy(obj.pMem, obj.pMem + MemSize, pMem);
}

void AlgSortStation::Put(const int &elem)
{
	if (pMem == nullptr)
		throw "error";
	if (!IsFull())
	{
		pMem[++top] = elem;
		DataCount++;
	}
	else
	{
		throw "Stack is full";
	}
}
void AlgSortStation::Pop()
{
	if (pMem == nullptr)
		throw "DataNoMem";
	if (!IsEmpty())
	{
		top--;
		DataCount--;
	}
	else
	{
		throw "Stack is empty";
	}
}
int AlgSortStation::Get()
{
	if (pMem == nullptr)
		throw "DataNoMem";
	if (!IsEmpty())
		return pMem[top];
	else
	{
		throw "Stack is empty";
	}
}

void AlgSortStation::Resize(int newLen)
{
	if (newLen > 0)
	{
		if (pMem != nullptr)
		{
			int *arr = new int[newLen];
			for (int i = 0; i < newLen; i++)
				arr[i] = 0;
			std::copy(pMem, pMem + MemSize, arr);
			delete[] pMem;
			pMem = arr;
		}
		else
			pMem = new int[newLen];
		MemSize = newLen;
	}
	else if (newLen == 0)
	{
		if (pMem != nullptr)
			delete[] pMem;
		MemSize = newLen;
	}
	else
		throw "Wrong size of Stack";
}

int AlgSortStation::IsValid()
{
	if (pMem == NULL)
	{
		std::cout << "Stack don't have memory";
		return 1;
	}
	if (MemSize >= DataCount)
	{
		for (int i = 0; i < DataCount; i++)
			std::cout << pMem[i] << std::endl;
		std::cout << "Stack is Valid" << std::endl;
		this->Get();
		this->Pop();
		return 1;
	}
	else
		return 0;
}

void AlgSortStation::Print()
{
	std::cout << "top -> " << pMem[top] << std::endl;
	for (int i = top; i >= 0; i--)
		std::cout << pMem[i] << std::endl;
}
