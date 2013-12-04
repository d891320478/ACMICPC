#include<stdio.h>
#include <cstring>
int f[510][510],h[510],vh[510];	int m,n,ans;	int s,t;
int min(int x,int y)
{	if (x<y) return x;		else return y;	}
int dfs(int v,int flow)
{
	int i,j,k,minh;
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
	int i,j,k,c,into[510],out[510];
	while (scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0)break;
		memset(f,0,sizeof(f));
		memset(vh,0,sizeof(vh));
		memset(h,0,sizeof(h));
		memset(into,0,sizeof(into));
		memset(out,0,sizeof(out));
		s=n+1; t=n+2;
		if(m==0)
		{
			printf("%d\n",n);
			continue;
		}
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			f[u][v]=1;
			out[u]++;
			into[v]++;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(into[i]==0 && out[i]!=0) f[s][i]=1000000;
			if(out[i]==0 && into[i]!=0) f[i][t]=1000000;
			if(out[i]==0 && into[i]==0) ans++;
		}
		n+=2;
		vh[s]=n+1;
		while (h[s]<=n) ans+=dfs(s,2000000000);
		printf("%d\n",ans);
	}
	return 0;
}