/*
    ACM 111 - History Grading
    The code is written on 2015/07/08 by Yu-Zhen Xie.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int eventNumber;
int correctOrder[25] = {0};
int studentOrder[25] = {0};
int array[25][25] = {0};
int LCS(void);

int main()
{
	cin >> eventNumber;

	for(int i = 1; i < eventNumber + 1; i++)
	{
		int n;
		cin >> n;
		correctOrder[n] = i;
	}

	while(1)
	{
		for (int i = 1; i < eventNumber + 1; i++)
		{
			int m;
			if ( cin >> m ) 
				studentOrder[m] = i;
			else 
				return 0;
		}
		cout << LCS() << endl;
	}

	return 0;
}

int LCS()
{
    for (int i = 1; i <= eventNumber; i++)
        for (int j = 1; j <= eventNumber; j++)
            if (correctOrder[i] == studentOrder[j])
                array[i][j] = array[i-1][j-1] + 1;
            else
                array[i][j] = max(array[i-1][j], array[i][j-1]);
 
    return array[eventNumber][eventNumber];
}