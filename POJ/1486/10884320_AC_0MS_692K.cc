#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int g[30][30],n;
struct point
{
	int x,y;
	void init(){scanf("%d%d",&x,&y);}
}ct[30][2],p[30];
int vis[30],q[30];
int dfs(int s)
{
	for(int i=1;i<=n;i++)
		if(g[s][i])
		if(! vis[i])
		{
			vis[i]=1;
			if(q[i]==-1 || dfs(q[i]))
			{
				q[i]=s;
				return 1;
			}
		}
	return 0;
}
int main ()
{
	int i,j,ttt=0,flag;
	while (scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
			scanf("%d %d %d %d",&ct[i][0].x,&ct[i][1].x,&ct[i][0].y,&ct[i][1].y);
		for(i=1;i<=n;i++) p[i].init();
		memset(g,0,sizeof(g));
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(p[i].x>=ct[j][0].x && p[i].x<=ct[j][1].x)
			if(p[i].y>=ct[j][0].y && p[i].y<=ct[j][1].y)
				g[i][j]=1;
		memset(q,-1,sizeof(q));
		int va=0;
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) va++;
		}
		flag=0;
		printf("Heap %d\n",++ttt);
		if(va<n)
		{
			printf("none\n\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			int aaa=q[i];
			g[aaa][i]=0;
			q[i]=-1;
			memset(vis,0,sizeof(vis));
			if(! dfs(aaa))
			{
				if(flag) printf(" ");
				printf("(%c,%d)",i+'A'-1,aaa);
				q[i]=aaa;
				flag++;
			}
			g[aaa][i]=1;
		}
		if(flag==0) printf("none");
		printf("\n\n");
	}
	
	return 0;
}