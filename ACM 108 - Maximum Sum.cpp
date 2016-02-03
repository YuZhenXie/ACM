/*
    ACM 108 - Maximum Sum
    The code is written on 2015/07/10 by Yu-Zhen Xie.
*/

#include <iostream>
#define MaxLength 101
using namespace std;

int array[MaxLength][MaxLength] = {0};
int sumX[MaxLength][MaxLength] = {0};
int sum[MaxLength][MaxLength] = {0};

int sumXY( int, int);

int main()
{
	int n;

	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> array[i][j];
				sumX[i][j] = sumX[i][j - 1] + array[i][j];
				sum[i][j] = sumXY(i, j);
			}
		}

		int answer = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int x = i; x <= n; x++)
				{
					for (int y = j; y <= n; y++)
					{
						int temp = sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];
						answer = temp > answer ? temp : answer;
					}
				}
			}
		}

		cout << answer << endl;

	}

	return 0;
}

int sumXY(int x, int y)
{
	int summary = 0;
	for(int m = 1; m <= x; m++)
	{
		summary += sumX[m][y]; 
	}

	return summary;
}