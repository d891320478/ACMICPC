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
int s,d;
int main ()
{
	while (scanf("%d%d",&s,&d)!=-1)
	{
		if(s*4-d<0)
		{
			if(s*10-2*d>0)printf("%d\n",s*10-2*d);
			else printf("Deficit\n");
		}
		else
		if(s*3-2*d<0)
		{
			if(s*8-4*d>0)printf("%d\n",s*8-4*d);
			else printf("Deficit\n");
		}
		else
		if(s*2-3*d<0)
		{
			if(s*6-6*d>0)printf("%d\n",s*6-6*d);
			else printf("Deficit\n");
		}
		else
		if(s-4*d<0)
		{
			if(s*4-8*d>0)printf("%d\n",s*4-8*d);
			else printf("Deficit\n");
		}else printf("Deficit\n");
	}
	
	return 0;
}