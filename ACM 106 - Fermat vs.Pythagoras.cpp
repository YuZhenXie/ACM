/*
	ACM 106 - Fermat vs. Pythagoras
	The code is written on 2015/07/12 by Yu-Zhen Xie.
*/

#include <iostream>
#include <math.h>
#include <string.h>
#define MaxInt 1000001
int array[MaxInt] = {0};
using namespace std;

int gcd(int, int);

int main()
{
	long int N;
	while(cin >> N)
	{
		long int PythagoreanTripleCount = 0;
		memset(array, 0, sizeof(array));
		for (long int i = 1; i <= sqrt(MaxInt); i++)
		{
			for (long int j = i + 1;; j+=2)
			{
				if (gcd(i, j) != 1) continue;
				if (pow(i, 2) + pow(j, 2) > N) break;
				int A = pow(j, 2) - pow(i, 2);
				int B = 2 * i * j;
				int C = pow(j, 2) + pow(i, 2);
				array[A] = array[B] = array[C] = 1;
				PythagoreanTripleCount++;

				long int nA = A, nB = B, nC = C;
				while(nC <= N)
				{
					array[nA] = array[nB] = array[nC] = 1;
					nA += A;
					nB += B;
					nC += C;
				}
			}
		}

		long int notPTNumber = 0;
		for (long int i = 1; i <= N; i++)
		{
			if (array[i] == 0) notPTNumber++;
		}
	
		cout << PythagoreanTripleCount << " " << notPTNumber << endl;

	}

	return 0;
}

int gcd(int m, int n)
{
    int k;
    while (k = m % n)
    {
        m=n;
        n=k;
    }
    return n;
}
