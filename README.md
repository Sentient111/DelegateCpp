# DelegateCpp
Easy to use delegate class for c++                                         
This class can hold multiple functions and execute them all at once on demand.                                   

## How to use:
In Test.cpp is a simple example.

adding a function (both do the same)
 ```
myDel.Add(Test); 
myDel + Test;
```
removing a function (both do the same)
```
myDel.Remove(Test);
myDel - Test;
```

running delegate (you know the drill)
```
myDel.Execute();
myDel();
```

getting element of delegate
```
myDel[2]; //returns NULL or nullptr when index out of bound
```
                                          
