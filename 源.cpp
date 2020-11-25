#include <iostream>
#include "head.h"

int main()
{
	cout << "Hi, Master!" << endl;

	string s = "( ( 1 + 2 ) / ( 4 - 5 ) ) * 6";
	SNode S = WriteIn(s);
	SNode R = MidToRear(S);
	double sum = atof(Operation(R).c_str());

	/*for (int i = 0;i < S.rear - S.front + 1;i++) {
		cout << S.Data[i] << "\t";
	}
	cout<< S.front << endl;
	cout << S.rear << endl;
	for (int i = 0;i < R.rear - R.front + 1;i++) {
		cout << R.Data[i] << "\t";
	}*/
	
	cout << fixed << setprecision(2) << "The sum is: " << sum << endl;

	cout << "Program is over!" << endl;
	return 0;
}