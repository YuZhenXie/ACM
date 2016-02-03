/*
	ACM 10041 - Vito's family 
	The code is written on 2015/07/17 by Yu-Zhen Xie.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;
int compare (const void *, const void *);
int main()
{
	int testCount, r;
	cin >> testCount;
	for (int m = 0; m < testCount; m++)
	{
		cin >> r;
		int * familyNo = new int [r];

		for (int i = 0; i < r; i++)
		{
			cin >> familyNo[i];
		}

		qsort(familyNo, r, sizeof(int), compare);

		int center = r / 2, sum = 0;
		int doorNo = r % 2 != 0 ? familyNo[center] : (familyNo[center - 1] + familyNo[center]) / 2;

		for (int i = 0; i < r; i++)
		{
			sum += abs(familyNo[i] - doorNo);
		}

		cout << sum << endl;
		free(familyNo);
	}
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}