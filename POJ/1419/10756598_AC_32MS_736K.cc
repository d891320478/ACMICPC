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
#define N 110
#define M 10010
int a[N][N],n,m,ret[N];
void clique(int n,int *u,int a[][N],int size,int &max,int &bb,int *res,int *rr,int *c)
{
	int i,j,vn,v[N];
	if(n)
	{
		if(size+c[u[0]]<=max) return;
		for(i=0;i<n+size-max && i<n;i++)
		{
			for(j=i+1,vn=0;j<n;j++)
				if(a[u[i]][u[j]]) v[vn++]=u[j];
			rr[size]=u[i];
			clique(vn,v,a,size+1,max,bb,res,rr,c);
			if(bb) return;
		}
	}
	else if(size>max)
	{
		max=size;
		for(i=0;i<size;i++)
			res[i]=rr[i];
		bb=1;
	}
}
int maxclique(int n,int a[][N],int *ret)
{
	int max=0,bb,c[N],i,j;
	int vn,v[N],rr[N];
	for(c[i=n-1]=0;i>=0;i--)
	{
		for(vn=0,j=i+1;j<n;j++)
			if(a[i][j]) v[vn++]=j;
		bb=0;
		rr[0]=i;
		clique(vn,v,a,1,max,bb,ret,rr,c);
		c[i]=max;
	}
	return max;
}
int main ()
{
	int tttt,i,j;
	scanf("%d",&tttt);
	while (tttt--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=1;
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			a[u][v]=a[v][u]=0;
		}
		int ans=maxclique(n,a,ret);
		printf("%d\n",ans);
		printf("%d",ret[0]+1);
		for(i=1;i<ans;i++) printf(" %d",ret[i]+1);
		printf("\n");
	}
	
	return 0;
}