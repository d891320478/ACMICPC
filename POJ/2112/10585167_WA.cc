#include<stdio.h>
#include <cstring>
int f[300][300],h[300],vh[300];	int m,n,ans;	int s,t;
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
	int i,j,l,k,c,m;
	int dist[300][300];
	while(scanf("%d%d%d",&k,&c,&m)!=EOF)
	{
		n=t=k+c+2; s=k+c+1;
		for(i=1;i<s;i++)
		for(j=1;j<s;j++)
		{
			scanf("%d",&dist[i][j]);
			if(i!=j && dist[i][j]==0)
				dist[i][j]=1600000000;
		}
		for(l=1;l<s;l++)
		for(i=1;i<s;i++)
		for(j=1;j<s;j++)
			if(dist[i][j]>dist[i][l]+dist[l][j])
				dist[i][j]=dist[i][l]+dist[l][j];
		int lft=1,mid,rht=50000;
		while(lft<rht)
		{
			mid=(lft+rht)/2;
			memset(f,0,sizeof(f));
			memset(vh,0,sizeof(vh));
			memset(h,0,sizeof(h));
			for(i=1;i<=c;i++)
				f[s][i]=1;
			for(i=1;i<=k;i++)
				f[i+c][t]=m;
			for(i=1;i<=c;i++)
			for(j=1;j<=k;j++)
				if(dist[j][i+k]<=mid)
				f[i][j+c]=1;
			vh[s]=n+1;ans=0;
			while (h[s]<=n) ans=ans+dfs(s,2000000000);
			if(ans>=c)rht=mid;
			else lft=mid+1;
		}
		printf("%d\n",lft);
	}
	return 0;
}