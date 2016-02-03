/*
	ACM 900 - Brick Wall Patterns
	The code is written on 2015/07/17 by Yu-Zhen Xie.
*/

#include <stdio.h>
#include <inttypes.h>

int main(){
  long long int dp[55] = {0,1,2};
  int n;
  for( int i = 3 ; i <= 50 ; i++ )
    dp[i] = dp[i-1]+dp[i-2];
  while( scanf( "%d", &n ) != EOF && n )
    printf( "%lld\n", dp[n] );
  return 0;
}