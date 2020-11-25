#pragma once
#ifndef  _H_H_
#define _H_H_
#include <string>
#include <iomanip>
//#include <cctype>

#define MAXSIZE 30

using namespace std;

//¶¨ÒåË«ÏòÕ»
struct SNode
{
	string Data[MAXSIZE];
	int front = 0;
	int rear = 0;
	//int Maxsize;
};

//fuc
int WitchOp(string S);
bool IsFullSN(SNode S);
bool IsEmptySN(SNode S);
bool IsOp(string S);
SNode MidToRear(SNode S);
SNode WriteIn(string S);
SNode Push(SNode& S, string St);
string Operation(SNode S);
string PopFront(SNode& S);
string Pop(SNode& S);

#endif // ! _H_H_

