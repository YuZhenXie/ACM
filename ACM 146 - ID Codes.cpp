/*
    ACM 146 - ID Codes
    The code is written on 2015/07/13 by Yu-Zhen Xie.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string codeStr;
	while(cin >> codeStr)
	{
		if ( codeStr.compare("#") == 0) break;
		vector<char> codeVector;
		for (int i = 0; i < codeStr.length(); i++)
		{
			codeVector.push_back(codeStr[i]);
		}
		
		if(next_permutation(codeVector.begin(), codeVector.end()))
		{
			for (int i = 0; i < codeVector.size(); i++)
			{
				cout << codeVector[i];
			}
		}
		else
		{
			cout << "No Successor";
		}
		
		cout << endl;

	}
	return 0;
}