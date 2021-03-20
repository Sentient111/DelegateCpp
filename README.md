# DelegateCpp
Easy to use delegate class for c++
This class can hold multiple functions and execute them all at once on demand.
Example: You have multiple buttons in a UI and you need to keep track of active buttons.
Checking every frame if a button is true for each function is not good. Adding all active functions to a Delegate and removing them when a button is toggled will save some performance.

## How to use:
In Test.cpp is a simple example.                
Make sure to define a reasonable array size in the Delegate class that holds the functions.                                
Create a Delegate object with: ```Delegate myDelegate {};```                                                     
Add the functions you want to run to it with: ```myDelegate.Add((DWORD)MyFunctionName);```                                    
Execute every function inside it with ```myDelegate.Execute();```                                       
Remove functions with ```myDelegate.Remove((DWORD)MyFunctionName);```                                            

## Why is this made?
I did a little bit of searching around since I needed it in one of my projects. It apears that there is not such a simple solution like in c#, so I decided to make my own one.
