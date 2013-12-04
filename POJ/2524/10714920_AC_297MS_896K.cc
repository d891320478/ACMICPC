#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 50010
#define M 10010
int pnt[N],m,n,u,v,i,x,y,sum,tt=0;
int find(int x)
{
	if(x!=pnt[x]) pnt[x]=find(pnt[x]);
	return pnt[x];
}
int main ()
{
	while (scanf("%d%d",&n,&m) && (n||m))
	{
		for(i=1;i<=n;i++) pnt[i]=i;
		while (m--)
		{
			scanf("%d%d",&u,&v);
			x=find(u);
			y=find(v);
			if(x!=y)pnt[y]=x;
		}
		sum=0;
		for(i=1;i<=n;i++) sum+=(pnt[i]==i);
		printf("Case %d: %d\n",++tt,sum);
	}
	
	return 0;
}