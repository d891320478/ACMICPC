#include<stdio.h>
#include <cstring>
int f[2010][2010],h[2010],vh[2010],x[2010],y[2010];
int n,ff,d,ans,m;
int s,t;
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
	int i,j,k,l,c;
	while(scanf("%d%d%d",&m,&ff,&d)!=EOF)
	{
		memset(f,0,sizeof(f));
		memset(vh,0,sizeof(vh));
		memset(h,0,sizeof(h));
		s=1;t=m+ff+d+2;
		n=t;
		for(i=2;i<=m+1;i++)
			f[s][i]=1;
		for(i=m+ff+2;i<t;i++)
			f[i][t]=1;
		for(i=2;i<=m+1;i++)
		{
			scanf("%d%d",&k,&l);
			for(j=1;j<=k;j++)
			{
				scanf("%d",&x[i]);
				f[i][m+1+x[i]]=1;
			}
			for(j=1;j<=l;j++)
			{
				scanf("%d",&y[i]);
				for(c=1;c<=k;c++)
					f[m+1+x[i]][m+d+1+y[i]]++;
			}	
		}
		//scanf("%d%d",&s,&t);
		vh[s]=n+1;ans=0;
		while (h[s]<=n) ans=ans+dfs(s,2000000000);
		printf("%d\n",ans);
	}
	return 0;
}
