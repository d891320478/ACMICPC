#include <cstdio>
#include <cstring>
#define N 110
bool flag[N],a[N][N];
int ans,cnt[N],group[N],m,n,vis[N];
bool dfs(int u,int vis[],int pos)
{
	int i,j;
	for(i=u+1;i<=n;i++)
	{
		if(cnt[i]+pos<=ans) return 0;
		if(a[u][i])
		{
			for(j=0;j<pos;j++) if(! a[i][vis[j]]) break;
			if(j==pos)
			{
				vis[pos]=i;
				if(dfs(i,vis,pos+1)) return 1;
			}
		}
	}
	if(pos>ans)
	{
		for(i=0;i<pos;i++) group[i]=vis[i];
		ans=pos;
		return 1;
	}
	return 0;
}
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			a[u][v]=a[v][u]=1;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) a[i][j]=1-a[i][j];
		ans=-1;
		for(int i=n;i>0;i--)
		{
			vis[0]=i;
			dfs(i,vis,1);
			cnt[i]=ans;
		}
		printf("%d\n",ans);
		for(int i=0;i<ans;i++)
		{
			printf("%d",group[i]);
			if(i<ans-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}