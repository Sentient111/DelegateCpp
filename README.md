# DelegateCpp
Easy to use delegate class for c++


## How to use:
In Test.cpp is a simple example.  
Make sure to define a reasonable array size in the Delegate class that holds the functions.
Create a Delegate object with: ```Delegate myDelegate {};```
Add the functions you want to run to it with: ```myDelegate.Add((DWORD)MyFunctionName);```
Execute every function inside it with ```myDelegate.Execute();```
Remove functions with ```myDelegate.Remove((DWORD)MyFunctionName);```

## Why is this made?
I did a little bit of searching around since I needed it in one of my projects and did not find a simple solution like the one in c#.
