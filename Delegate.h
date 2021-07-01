#pragma once
#include <Windows.h>
#include <vector>

class Delegate
{
public:
	//ctor
	Delegate() = default;

	//variables
	std::vector<void*> functions;
	int count = 0;

	//functions
	bool Add(void* func);
	bool Remove(void* func);
	void Execute();

	//overloads
	bool operator+(void* func) { return this->Add(func); }
	bool operator-(void* func) { return this->Remove(func); }
	void operator()() { this->Execute(); }

	void* operator[](int i) 
	{ 
		if (i > count)
			return nullptr;

		return this->functions[i]; 
	}

private:
	void RemoveArrayItem(int pos);
};


void Delegate::Execute()
{
	for (int i = 0; i < this->count; i++)
	{
		void(*pointer)();
		pointer = (void(*)())this->functions[i];
		pointer();
		this->functions[i];
	}
	return;
}

bool Delegate::Add(void* func)
{

	if (std::find(this->functions.begin(), this->functions.end(), func) != this->functions.end())
		return false;

	this->functions.push_back(func);
	this->count++;
	return true;
}

bool Delegate::Remove(void* func)
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
