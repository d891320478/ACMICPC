#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
unsigned int a,x,y;
int main ()
{
	scanf("%x,%u,%u",&a,&x,&y);
	if((a>>x) & 1) a-=(1<<x);
	if(((a>>(y)) & 1)==0) a+=(1<<(y));
	//printf("%u\n",a);
	if(((a>>(y-1)) & 1)==0) a+=(1<<(y-1));
	if((a>>(y-2)) & 1) a-=(1<<(y-2));
	printf("%x\n",a);
	//printf("%u\n",a);
	
	return 0;
}