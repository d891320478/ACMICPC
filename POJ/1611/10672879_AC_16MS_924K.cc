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
#define N 30010
int pnt[N],n,m,k,num[N],i;
int find(int x)
{
	if(x!=pnt[x]) pnt[x]=find(pnt[x]);
	return pnt[x];
}
int main ()
{
	while (scanf("%d%d",&n,&m) && (n || m))
	{
		if(m==0)
		{
			printf("1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			pnt[i]=i;
			num[i]=1;
		}
		while (m--)
		{
			int u,v,x,y,k;
			scanf("%d%d",&k,&u);
			k--;
			x=find(u);
			while (k--)
			{
				scanf("%d",&v);
				y=find(v);
				if(y!=x)
				{
					pnt[y]=x;
					num[x]+=num[y];
					num[y]=0;
				}
			}
		}
		printf("%d\n",num[find(0)]);
	}
	
	return 0;
}