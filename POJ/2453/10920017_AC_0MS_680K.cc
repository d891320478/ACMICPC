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
int a,b,i,c[40],j,sum;
int main ()
{
	while (scanf("%d",&a) && a)
	{
		sum=b=0;
		SET(c,0);
		while (a)
		{
			c[++c[0]]=a & 1;
			a>>=1;
		}
		for(i=1;i<=c[0];i++)
			if(c[i] && ! c[i+1])
			{
				swap(c[i],c[i+1]);
				break;
			}
		for(j=1;j<=i;j++) if(c[j]) sum++,c[j]=0;
		for(j=1;j<=sum;j++) c[j]=1;
		if(c[c[0]+1]) ++c[0];
		for(j=1;j<=c[0];j++) b+=(c[j]<<(j-1));
		printf("%d\n",b);
	}
	
	return 0;
}