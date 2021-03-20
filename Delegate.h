#pragma once
#include <Windows.h>

class Delegate
{
public:
	Delegate();
	DWORD functions[10];
	int count = 0;

	bool Add(DWORD func);
	void Execute();
	bool Remove(DWORD func);

	void RemoveArrayItem(int pos);
};

Delegate::Delegate()
{
}

void Delegate::Execute()
{
	for (int i = 0; i < this->count; i++)
	{
		void(*pointer)();
		pointer = (void(*)())this->functions[i];
		pointer();
	}
	return;
}

bool Delegate::Add(DWORD func)
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->functions[i] == func)
		{
			return false;
		}
	}
	this->functions[this->count] = func;
	this->count++;
	return true;
}

bool Delegate::Remove(DWORD func)
{
	for (int i = 0; i < this->count; i++)
	{
		if (func == this->functions[i])
		{
			RemoveArrayItem(i);
			this->count--;
			return true;
		}
	}
	return false;
}

void Delegate::RemoveArrayItem(int pos)
{
	for (int i = pos; i < this->count; i++)
	{
		this->functions[i] = this->functions[i + 1];
	}
}