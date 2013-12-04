#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 110
#define M 10010
int n,m,t,dp[N],ans;
struct gangs
{
	int a,b,c;
}g[N];
int cmp(gangs a,gangs b)
{
	return a.a<b.a;
}
int main()
{
	while (scanf("%d%d%d",&n,&m,&t)!=-1)
	{
		for(int i=1;i<=n;i++) scanf("%d",&g[i].a);
		for(int i=1;i<=n;i++) scanf("%d",&g[i].b);
		for(int i=1;i<=n;i++) scanf("%d",&g[i].c);
		g[0]=(gangs){0,0,0};
		ans=0;
		sort(g+1,g+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			dp[i]=0;
			for(int j=0;j<i;j++)
				if(abs(g[i].c-g[j].c)<=abs(g[i].a-g[j].a))
				if(dp[i]<dp[j]+g[i].b) dp[i]=dp[j]+g[i].b;
			if(dp[i]>ans) ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}