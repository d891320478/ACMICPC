#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;
#define N 110
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
			ma[i][j]=(i==j);
		for(i=1;i<=m;i++)	
		{
			cin>>a1>>c>>a2;
			ma[pt[a1]][pt[a2]]=c;
		}
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ma[i][j]=max(ma[i][j],ma[i][k]*ma[k][j]);
		min=-1.0;
		for(i=1;i<=n;i++)
			if(ma[i][i]>1){min=2.0;break;}
		tt++;
		if(min>1.0) printf("Case %d: Yes\n",tt);
		else printf("Case %d: No\n",tt);
	}
	return 0;
}