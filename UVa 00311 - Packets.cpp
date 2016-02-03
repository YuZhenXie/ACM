/*
	UVa 00311 - Packets
	The code is written on 2016/02/03 by Yu-Zhen Xie. 
*/

#include <iostream>

using namespace std;

int countArr[6] = {0};
int zeroCount = 0;
int boxCount = 0;

int main() {
	while (cin >> countArr[0] >> countArr[1] >> countArr[2] >> countArr[3] >> countArr[4] >> countArr[5]) {
		zeroCount = boxCount = 0;
		for (int i = 0; i < 6; i++) {
			if (countArr[i] == 0) zeroCount++;
		} 
		if (zeroCount == 6) break;

		// size 4 * 4, 5 * 5, and 6 * 6
		boxCount += countArr[3] + countArr[4] + countArr[5];
		
		countArr[0] -= countArr[4] * 11;

		int cap = countArr[3] * 5;
		while (cap > 0 && countArr[1] > 0) {
			cap--; countArr[1]--;
		}

		cap *= 4;
		while (cap > 0 && countArr[0] > 0) {
			countArr[0]--; cap--;
		}

		// size 3 * 3
		boxCount += countArr[2] / 4;
		int remaindedThree = countArr[2] % 4;
		boxCount = remaindedThree > 0 ? boxCount + 1 : boxCount;
		
		switch (remaindedThree) {
			case 1:
				countArr[1] -= 5;
				countArr[0] -= 7;
				break;
			case 2:
				countArr[1] -= 3;
				countArr[0] -= 6;
				break;
			case 3:
				countArr[1] -= 1;
				countArr[0] -= 5;
				break;
		}

		// size 2 * 2
		if (countArr[1] > 0) {
			boxCount += countArr[1] / 9;
			if (countArr[1] % 9 > 0) boxCount++;
		}
		// size 1 * 1
		if (countArr[1] % 9 > 0) countArr[0] -= 36 - countArr[1] % 9 * 4;
		if (countArr[0] > 0) {
			boxCount += countArr[0] / 36;
			if (countArr[0] % 36 > 0) boxCount++;
		}
		cout << boxCount << endl;
	}

	return 0;
}