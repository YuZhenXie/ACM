/*
	UVa 587 There's treasure everywhere!
	The code is written on 2016/02/02 by Yu-Zhen Xie. 
*/

#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

float unit = 1 / sqrt(2);

bool isComma(char c){
    return (c==',' || c=='.');
}

int main() {

	int mapCount = 0;
	string line;
	float x_pos = 0, y_pos = 0;

	while (cin >> line) {

		if (line.compare("END") == 0) break;

		mapCount++;
		replace_if( line.begin(), line.end(), isComma, ' ');
		istringstream sin(line);
		string dir;
		int stepCount;

		while( sin >> stepCount >> dir) {
			if (dir == "NE") {
				y_pos += stepCount * unit;
				x_pos += stepCount * unit;
			}else if ( dir == "SE") {
				y_pos -= stepCount * unit;
				x_pos += stepCount * unit;
			}else if ( dir == "SW") {
				y_pos -= stepCount * unit;
				x_pos -= stepCount * unit;
			}else if ( dir == "NW") {
				y_pos += stepCount * unit;
				x_pos -= stepCount * unit;
			}else if ( dir == "N") {
				y_pos += stepCount;
			}else if ( dir == "W") {
				x_pos -= stepCount;
			}else if ( dir == "S") {
				y_pos -= stepCount;
			}else if ( dir == "E") {
				x_pos += stepCount;
			}
		}


		if (mapCount > 1) cout << endl;
		cout << fixed << setprecision(3);
		cout << "Map #" << mapCount << endl;
		cout << "The treasure is located at (" << x_pos << "," << y_pos << ")." << endl;
		cout << "The distance to the treasure is " << sqrt(pow(x_pos, 2) + pow(y_pos, 2)) << "." << endl;
		x_pos = y_pos = 0;
	}

	return 0;
}