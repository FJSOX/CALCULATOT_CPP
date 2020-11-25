#include <iostream>
#include "head.h"


bool IsEmptySN(SNode S)
{
	if (S.front == S.rear) {
		return true;
	}
	else {
		return false;
	}
}

bool IsFullSN(SNode S)
{
	if (MAXSIZE == S.rear) {
		return true;
	}
	else {
		return false;
	}
}

bool IsOp(string S)
{
	if (S == "+" || S == "-" || S == "*" || S == "/" || S == "(" || S == ")") {
		return true;
	}
	else
	{
		return false;
	}
}

int WitchOp(string S) 
{
	if (S == "+") {
		return 0;
	} 
	else if (S == "-") {
		return 1;
	}
	else if (S == "*") {
		return 2;
	}
	else if (S == "/") {
		return 3;
	}
	else {
		return 4;
	}
}

string Pop(SNode &S)
{
	string s;
	if (IsEmptySN(S)) {
		cout << "Stack is empty!" << endl;
		return NULL;
	}
	else {
		s = S.Data[S.rear-1];
		S.Data[S.rear-1]="";
		S.rear--;
		return s;
	}
}

string PopFront(SNode& S)
{
	string s;
	if (IsEmptySN(S)) {
		cout << "Stack is empty!" << endl;
		return NULL;
	}
	else {
		s = S.Data[S.front];
		S.Data[S.front] = "";
		S.front++;
		return s;
	}
}

SNode Push(SNode& S, string St)
{
	S.Data[S.rear++] = St;
	return S;
}

SNode WriteIn(string S)
{
	SNode s;
	int i = 0;
	int j = 0;

	while (S[i]) {
		if (S[i] == ' ') {
			i++;
			j++;
			s.rear++;
		}
		while (S[i])
		{
			s.Data[j] += S[i];
			i++;
			if (S[i] == ' ') {
				break;
			}
		}
	}

	return s;
}

SNode MidToRear(SNode S)
{
	int p = 0;
	SNode r, op;
	int pr = 0;

	while (S.Data[p]!="")
	{
		if (IsOp(S.Data[p])) {
			if (IsEmptySN(op)) {
				Push(op, S.Data[p]);
				p++;
			}
			else {
				if (S.Data[p] == ")") {
					string o = Pop(op);
					while (o!="(")
					{
						Push(r, o);

						o=Pop(op);
					}
					p++;
				}
				else if (WitchOp(op.Data[op.rear - 1]) / 2 >= WitchOp(S.Data[p])/2) {
					if (op.Data[op.rear - 1] != "(") {
						Push(r, Pop(op));
						Push(op, S.Data[p]);
					}
					else {
						Push(op, S.Data[p]);
					}
					p++;
				}
				else {
					Push(op, S.Data[p]);
					p++;
				}
			}
		}
		else if(!IsOp(S.Data[p])) {
			Push(r, S.Data[p]);
			p++;
		}
	}

	while (op.front!=op.rear)
	{
		Push(r, Pop(op));
	}

	return r;
}

string Operation(SNode S)
{
	SNode N;
	double num1, num2;
	int op;
	double sum=0;
	string st;

	while (S.front!=S.rear)
	{
		st = PopFront(S);

		if (!IsOp(st)) {
			N.Data[N.rear++] = st;
		}
		else {
			op = WitchOp(st);
			num2 = atof(Pop(N).c_str());
			num1 = atof(Pop(N).c_str());
			switch (op)
			{
				case 0:
				sum = num1 + num2;
				break;
				case 1:
					sum = num1 - num2;
					break;
				case 2:
					sum = num1 * num2;
					break;
				case 3:
					//if (num2 == 0) 
					sum = num1 / num2;
					break;
				default:
					break;
			}

			Push(N, to_string(sum));
		}
	}

	return N.Data[N.front];
}