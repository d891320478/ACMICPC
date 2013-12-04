#include<stdio.h>
#include <cstring>

long long f[201][201],g[201][201],h[201],vh[201],a[1001];
long long m,n,ans,s,t;
int u[1001];

long long min(long long x,long long y)
{
	if (x<y) return x;
	else return y;
}

long long dfs(long long v,long long flow)
{
	long long i,j,k,minh;

	if (v==t) return flow;
	minh=n+2;
	k=0;
	for (i=1;i<=n+2;i++)
	if (f[v][i]>0)
	{
		if (h[v]==h[i]+1) {k=dfs(i,min(flow,f[v][i]));}
		if (h[s]>n+2) return 0;
		if (k>0)
		{
			f[v][i]-=k;
			f[i][v]+=k;
			return k;
		} 
		minh=min(minh,h[i]);
	}
	vh[h[v]]--;
	if (vh[h[v]]==0) h[s]=n+3;
	h[v]=minh+1;
	vh[h[v]]++;

	return 0;
}
int main()
{
	long long i,j,k,c;
	scanf("%lld%lld",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	s=n+1;
	t=n+2;
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&g[i][0]);
		for(j=1;j<=g[i][0];j++)
			scanf("%lld",&g[i][j]);
		scanf("%lld",&f[i][t]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=g[i][0];j++)
		{
			if(! u[g[i][j]])
			{
				u[g[i][j]]=i;
				f[s][i]+=a[g[i][j]];
			}
			else
			{
				f[u[g[i][j]]][i]=10000000;
				u[g[i][j]]=i;
			}
		}
	}
	vh[s]=n+2;
	while (h[s]<=n+2) ans=ans+dfs(s,10000000);
	printf("%lld\n",ans);
	
	return 0;
}
