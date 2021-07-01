#include <iostream>
#include "Delegate.h"


Delegate myDel;

void Test()
{
	std::cout << "ran func" << std::endl;
}


int main()
{
	//adding a function (both do the same)
	myDel.Add(Test); 
	myDel + Test;

	//removing a function (both do the same)
	myDel.Remove(Test);
	myDel - Test;

	//running delegate (you know the drill)
	myDel.Execute();
	myDel();

	//getting element of delegate
	myDel[2]; //returns NULL or nullptr when index out of bound
}
