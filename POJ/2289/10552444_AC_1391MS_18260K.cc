#include<cstdio>
#include <cstring>
#define N 1510
int c[N][N],f[N][N],h[N],vh[N];
int m,n,o,ans;
int s,t;
char ch,name[110];
int lft,rht,mid;
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
	int i,j,k,d;
	while(scanf("%d%d",&o,&m))
	{
		if(o==0 && m==0)break;
		s=m+o+1;n=t=s+1;
		memset(c,0,sizeof(c));
		for(i=1;i<=o;i++)
		{
			scanf("%s",name);
			while (scanf("%d%c",&d,&ch))
			{
				c[i][++c[i][0]]=d;
				if(ch=='\n')break;
			}
		}
		lft=1;rht=o;
		while (lft<rht)
		{
			mid=(lft+rht)/2;
			memset(f,0,sizeof(f));
			for(i=1;i<=o;i++)
			{
				f[s][i]=1;
				for(j=1;j<=c[i][0];j++)
					f[i][o+c[i][j]+1]=1;
			}
			for(i=o+1;i<s;i++)
				f[i][t]=mid;
			memset(vh,0,sizeof(vh));
			memset(h,0,sizeof(h));
			vh[s]=n+1;ans=0;
			while (h[s]<=n) ans=ans+dfs(s,2000000000);
			if(ans>=o)rht=mid;
			else lft=mid+1;
		}
		printf("%d\n",lft);
	}
	return 0;
}