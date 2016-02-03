/*
	ACM 113 - Power of Cryptography
	The code is written on 2015/07/09 by Yu-Zhen Xie.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double n, p;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(0);
	while (cin >> n >> p)
	{
		cout << pow(p, 1 / n) << endl;
	}

	return 0;
}