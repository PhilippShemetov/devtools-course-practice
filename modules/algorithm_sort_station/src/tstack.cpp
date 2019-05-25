#include <iostream>
#include "../include/tstack.h"

TStack::TStack() : MemSize(25)
{
	pMem = new int[MemSize];
	DataCount = 0;
	top = -1;
	for (int i = 0; i < MemSize; i++)
		pMem[i] = 0;
}

TStack::TStack(const TStack &obj)
{
	MemSize = obj.MemSize;
	top = obj.top;
	pMem = new int[MemSize];
	std::copy(obj.pMem, obj.pMem + MemSize, pMem);
}

void TStack::SetMem(int Size)
{
	MemSize = Size;
}

void TStack::Put(const int &elem)
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
void TStack::Pop()
{
	if (pMem == nullptr)
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
int TStack::Get()
{
	if (pMem == nullptr)
		if (!IsEmpty())
			return pMem[top];
		else
		{
			throw "Stack is empty";
		}
}
void TStack::Resize(int newLen)
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

int TStack::IsValid()
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

void TStack::Print()
{
	std::cout << "top -> " << pMem[top] << std::endl;
	for (int i = top; i >= 0; i--)
		std::cout << pMem[i] << std::endl;
}

int PriorityOper(char sign)
{
	switch (sign)
	{
	case '(':
		return 0;
		break;
	case ')':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	}
}
