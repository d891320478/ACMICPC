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
int n,m,d,a[1010][17],vis[17],ans,b[1010];
int check()
{
	int i,j,sum=0,ch=0;
	sum=0;
	for(j=0;j<m;j++)
		ch+=((1-vis[j+1])<<j);
	for(i=1;i<=n;i++)
		if( (ch & b[i])==0 ) sum++;
	return sum;
}
void dfs(int start,int step)
{
	if(step>d)
	{
		int sum=check();
		ans=ans>sum?ans:sum;
		return;
	}
	for(int i=start;i<=n;i++)
	{
		vis[i]=1;
		dfs(i+1,step+1);
		vis[i]=0;
	}
}
int main ()
{
	
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++)
	{
		int j;
		scanf("%d",&j);
		while (j--)
		{
			int k;
			scanf("%d",&k);
			a[i][k]=1;
		}
		b[i]=0;
		for(j=0;j<m;j++)
			b[i]+=(a[i][j+1]<<j);
	}
	ans=0;
	dfs(1,1);
	printf("%d\n",ans);
	
	return 0;
}