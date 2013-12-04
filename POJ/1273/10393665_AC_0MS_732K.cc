#include<stdio.h>
#include <cstring>
long long f[210][210],h[210],vh[210];	long long m,n,ans;	int s,t;
long long min(long long x,long long y)
{	if (x<y) return x;		else return y;	}
long long dfs(long long v,long long flow)
{
	long long i,j,k,minh;
	if (v==t) return flow;
	minh=n;	k=0;
	for (i=1;i<=n;i++)
	if (f[v][i]>0)
	{
		if (h[v]==h[i]+1) {k=dfs(i,min(flow,f[v][i]));}
		if (h[s]>n) return 0;
		if (k>0)	{	f[v][i]-=k;	f[i][v]+=k;		return k;		} 
		minh=min(minh,h[i]);
	}
	vh[h[v]]--;	if (vh[h[v]]==0) h[s]=n+1;
	h[v]=minh+1;	vh[h[v]]++;
	return 0;
}
int main()
{
	long long i,j,k,c;
	while(scanf("%lld%lld",&m,&n)!=EOF)
	{
		memset(f,0,sizeof(f));
		memset(vh,0,sizeof(vh));
		memset(h,0,sizeof(h));
		for (i=0;i<m;i++)
		{		scanf("%lld%lld%lld",&j,&k,&c);		f[j][k]+=c;		}
		//scanf("%d%d",&s,&t);
		s=1;t=n;
		vh[s]=n+1;ans=0;
		while (h[s]<=n) ans=ans+dfs(s,2000000000);
		printf("%lld\n",ans);
	}
	return 0;
}