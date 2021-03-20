#include <iostream>
#include <Windows.h>
#include "Delegate.h"
using namespace std;


int Add();
int Remove();
int BlaBla();

Delegate myDel{};


int main()
{
    myDel.Add((DWORD)Add);
    myDel.Add((DWORD)Remove);
    myDel.Add((DWORD)BlaBla);
    myDel.Execute();

    cout << "Removing Function Add()..." << endl;
    myDel.Remove((DWORD)Add);
    myDel.Execute();
}


int Add()
{
    cout << "Function executed -> Add()" << endl;
    return 3;
}

int Remove()
{
    cout << "Function executed -> Remove()" << endl;
    return 2;
}

int BlaBla()
{
    cout << "Function executed -> BlaBla()" << endl;
    return 1;
}