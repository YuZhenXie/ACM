/*
	UVA 1301 Fishnet
	The code is written on 2016/1/7 by Yu-Zhen Xie.
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

int n = 0;

struct Point {
	double x, y;
};


Point** allPoints;


Point intersection(Point p1, Point p2, Point p3, Point p4) {
	Point ret;
	ret.x = 0; ret.y = 0;
	// Store the values for fast access and easy
	// equations-to-code conversion
	float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
	float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;
	 
	float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	// If d is zero, there is no intersection
	if (d == 0) return ret;
	 
	// Get the x and y
	float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
	float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
	float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
	 
	// Check if the x and y coordinates are within both lines
	if ( x < min(x1, x2) || x > max(x1, x2) ||
	x < min(x3, x4) || x > max(x3, x4) ) return ret;
	if ( y < min(y1, y2) || y > max(y1, y2) ||
	y < min(y3, y4) || y > max(y3, y4) ) return ret;
	 
	// Return the point of intersection
	
	ret.x = x;
	ret.y = y;
	return ret;
}




void CaculateIntersectionPoints() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			allPoints[i + 1][j + 1] = intersection(allPoints[0][j + 1], allPoints[n + 1][j + 1], allPoints[i+1][0], allPoints[i+1][n+1]);
		}
	}
}


//（a,b）（c,d）（e,f）（g,h）
// （a x d + c x f + e x h + g x b - b x c - d x e - f x g - h x a）

double Area(Point& a, Point& b, Point& c, Point& d) {
	return fabs (((a.y + b.y) * (a.x - b.x) + (b.y + c.y) * (b.x - c.x) + (c.y + d.y) * (c.x - d.x) + (d.y + a.y) * (d.x - a.x)) / 2);
}





double MaxArea() {

	double maxArea = 0;
	double tempArea = 1;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			tempArea = Area(allPoints[i][j], allPoints[i][j+1], allPoints[i+1][j+1], allPoints[i+1][j]);
			maxArea = tempArea > maxArea ? tempArea : maxArea;
		}
	}

	return maxArea;
}



int main() {
	
	while (cin >> n) {

		if (n == 0) {
			break;
		}
		
		allPoints = new Point*[n + 2];

		for (int i = 0; i < n + 2; i++) {
			allPoints[i] = new Point[n + 2];
		}

		for (int i = 0; i < 4; i++) {	
			for (int j = 0; j < n; j++) {
				int row, col;

				switch(i) {
					case 0:
						row = n + 1;
						col = j + 1;
						cin >> allPoints[row][col].x;
						allPoints[row][col].y = 0;
						break;
					case 1:
						row = 0;
						col = j + 1;
						cin >> allPoints[row][col].x;
						allPoints[row][col].y = 1;
						break;
					case 2:
						col = 0;
						row = n - j;
						cin >> allPoints[row][col].y;
						allPoints[row][col].x = 0;
						break;
					case 3:
						col = n + 1;
						row = n - j;
						cin >> allPoints[row][col].y;
						allPoints[row][col].x = 1;
						break;
				} 

			}
		}

		allPoints[0][0].x = 0;  allPoints[0][0].y = 1;
		allPoints[0][n+1].x = 1; allPoints[0][n+1].y = 1;
		allPoints[n+1][0].x = 0; allPoints[n+1][0].y = 0;
		allPoints[n+1][n+1].x = 1; allPoints[n+1][n+1].y = 0;

		/*
		for (int i = 0; i < n+2; i++)
		{
			for (int j = 0; j < n+2; j++)
			{
				cout << "point [" + to_string(i) + ", " + to_string(j) + " = " + to_string(allPoints[i][j].x) + " " + to_string(allPoints[i][j].y) << endl;
			}
			cout << endl;
		}
		*/

		CaculateIntersectionPoints();

		cout << fixed << setprecision(6) << MaxArea() << endl;


		for (int i = 0; i < n+2; i++) {
			delete[] allPoints[i];
		}

		delete[] allPoints;

	}
}