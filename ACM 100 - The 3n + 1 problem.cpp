/*
    ACM 100 - The 3n + 1 problem
    The code is written on 2015/07/21 by Yu-Zhen Xie.
*/


#include <iostream>
#include <cstdio>

using namespace std;

int CalculateMaxCycleLength(int, int);
int CalculateCycleLength(int);

int main()
{
     int a, b, maxCycleLength = 0;
     while(cin >> a)
     {
          cin >> b;
          maxCycleLength = a < b ? CalculateMaxCycleLength(a, b) : CalculateMaxCycleLength(b, a);
          cout << a << " " << b << " " << maxCycleLength << endl;
     }
     return 0;
}

int CalculateMaxCycleLength(int a, int b)
{
   int maxCycleLength = 0, temp = 0;
   for (int i = a; i <= b; i++)
   {
       temp = CalculateCycleLength(i);
       maxCycleLength = maxCycleLength < temp ? temp : maxCycleLength;
   }
   return maxCycleLength; 
}

int CalculateCycleLength(int a)
{
   int cycleLength = 1;
   while (a != 1)
   {
      a = a % 2 == 0 ? a / 2 : a * 3 + 1;
      cycleLength += 1; 
   }
   return cycleLength;
}
