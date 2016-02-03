/*
    ACM 109 - SCUDB Busters
    The code is written on 2015/07/16 by Yu-Zhen Xie.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 
using namespace std;

typedef long long coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
struct Point 
{ 
	int x, y; 
};

struct kingdom
{
	bool isDestroyed;
	Point power;
	vector<Point> houses;
};

coord2_t cross(const Point &, const Point &, const Point &);
bool isInside (Point, kingdom);
double kingdomArea(kingdom);
bool compare(Point, Point);

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (coord2_t)(B.y - O.y) - (A.y - O.y) * (coord2_t)(B.x - O.x);
}

bool compare(Point a, Point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
 
	// Sort points lexicographically
	sort(P.begin(), P.end(), compare);
 
	// Build lower hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}

int main()
{
	int siteNumber;
	vector<kingdom> kingdoms;
	while (cin >> siteNumber)
	{
		if (siteNumber == -1) break;
		int x, y;
		cin >> x >> y;
		kingdom k;
		k.power = Point{x,y};
		for (int i = 0; i < siteNumber - 1; i++)
		{
			cin >> x >> y;
			k.houses.push_back(Point{x,y});
		}
		k.houses = convex_hull(k.houses);
		k.isDestroyed = false;
		kingdoms.push_back(k);
	}

	vector<Point> missiles;
	int x, y; 
	while(cin >> x >> y)
	{
		missiles.push_back(Point{x, y});
	}

	for (int i = 0; i < kingdoms.size(); i++)
	{
		for (int j = 0; j < missiles.size(); j++)
		{
			if (kingdoms[i].isDestroyed) break;
			kingdoms[i].isDestroyed = isInside(missiles[j], kingdoms[i]);
		}
	}

	double area = 0.0;
	for (int i = 0; i < kingdoms.size(); i++)
	{
		area += kingdomArea(kingdoms[i]);
	}

	cout << fixed;
	cout << setprecision(2);
	cout << area;

	return 0;
}

bool isInside (Point missile, kingdom k) 
{
 
    for (int i = 1; i < k.houses.size(); ++i) 
    {
        if ( cross(k.houses[i-1], k.houses[i], missile) < 0)
            return false;
    }
    return true;
}

double kingdomArea(kingdom k)
{
	if (!k.isDestroyed) return 0;

	double area = 0;
    for(int i = 1; i < k.houses.size(); ++i)
        area += (k.houses[i-1].x * k.houses[i].y) - (k.houses[i].x * k.houses[i-1].y);
    return area / 2;

}