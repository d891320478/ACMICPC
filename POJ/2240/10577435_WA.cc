#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;
#define N 110
#define Max 1000000000
int n,m;
double dist[N][N],ma[N][N];
int tt=0;
int main()
{
	int i,j,k;
	int a,b;
	double c,min;
	while(scanf("%d",&n) && n)
	{
		map<string,int> pt;
		string a1,a2;
		for(i=1;i<=n;i++)
		{
			cin>>a1;
			pt[a1]=i;
		}
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)ma[i][j]=Max; else ma[i][j]=1.0;
		for(i=1;i<=m;i++)	
		{
			cin>>a1>>c>>a2;
			ma[pt[a1]][pt[a2]]=c;
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			dist[i][j]=ma[i][j];		
		min=-1;
		for(k=1;k<=n;k++)
		{
			for(i=1;i<=k;i++)
			{
				if(ma[k][i]<Max)
					for(j=1;j<=k;j++)
					{
						if(ma[j][k]<Max && dist[i][j]*ma[k][i]*ma[j][k]>min)
							min=dist[i][j]*ma[k][i]*ma[j][k];	
					}	
			}	
			for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(dist[i][j]<dist[i][k]*dist[k][j])
					dist[i][j]=dist[i][k]*dist[k][j];		
		}
		tt++;
		if(min>1.0) printf("Case %d: Yes\n",tt);
		else printf("Case %d: No\n",tt);
	}
	return 0;
}