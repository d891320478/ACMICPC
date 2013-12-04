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
int n,a[30][30],vis[30],color;
char s[30];
void dfs(int s)
{
	int i,j;
	for(i=1;i<=color;i++)
	{
		for(j=1;j<=n;j++)
			if(a[s][j] && vis[j]==i)break;
		if(j>n)
		{
			vis[s]=i;
			break;
		}
	}
	if(i>color)vis[s]=++color;
	for(i=1;i<=n;i++)
		if(! vis[i])
		if(a[i][j]) dfs(j);
}
int main ()
{
	int i,j;
	while (scanf("%d",&n) && n)
	{
		SET(a,0);
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			for(j=2;s[j];j++)
				a[s[0]-'A'+1][s[j]-'A'+1]=1;
		}
		color=0;
		SET(vis,0);
		for(i=1;i<=n;i++)
			if(! vis[i])dfs(i);
		printf("%d ",color);
		if(color==1)puts("channel needed.");
		else puts("channels needed.");
	}
	
	return 0;
}