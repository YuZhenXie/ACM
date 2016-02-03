/*
	ACM 102 - Ecological Bin Packing
	The code is written on 2015/05/22 by Yu-Zhen Xie.
*/
#include <iostream>
#include <string>

using namesapce std;

struct answer
{
	int maxMoveCount;
	string order;
};
answer countMaxMovement();
int countMovement(string);

struct bin
{
	int b, g, c; 
};
bin Bins[3];

string Orders[6] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main()
{
	answer eachAnswer;
	

	while (cin >> Bins[0].b)
	{
		cin >> Bins[0].g >> Bins[0].c >> Bins[1].b >> Bins[1].g >> Bins[1].c >> Bins[2].b >> Bins[2].g >> Bins[2].c;
		eachAnswer = countMaxMovement();
		cout << eachAnswer.order << " " << eachAnswer.maxMoveCount << endl;
	}


	return 0;
}

answer countMaxMovement()
{
	answer temp, rightAns;
	temp.maxMoveCount = rightAns.maxMoveCount = 0;

	for(int i = 0; i < 6; i++)
	{
		temp.maxMoveCount = countMovement(Orders[i]);
		rightAns.maxMoveCount = temp.maxMoveCount > rightAns.maxMoveCount ? temp.maxMoveCount : rightAns.maxMoveCount;
	} 

}