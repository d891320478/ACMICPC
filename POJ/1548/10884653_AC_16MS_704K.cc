#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 10010
#define M 10010
struct point
{
	int x,y;
}a[N];
int la,b,c,i;
int main ()
{
	while (scanf("%d%d",&b,&c))
	{
		if(b==-1 && c==-1) break;
		la=0;
		while (b && c)
		{
			for(i=1;i<=la;i++)
				if(a[i].x<=b && a[i].y<=c) break;
			a[i].x=b;
			a[i].y=c;
			if(i>la) la=i;
			scanf("%d%d",&b,&c);
		}
		printf("%d\n",la);
	}
	
	return 0;
}