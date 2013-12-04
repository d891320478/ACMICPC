#include <cstdio>
#define N 1010
int g[N][N],pnt[N];
int n,m,dis;
int a[N][2];
int dist(int *a,int *b)
{
	return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}
char ch,s;
int b,c,x,y;
bool vis[N];
int find(int x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int main ()
{
	int i,j;
	scanf("%d%d",&n,&dis);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d%c",&a[i][0],&a[i][1],&ch);
		for(j=1;j<i;j++)
		if(dist(a[i],a[j])<=dis*dis)
		{
			g[i][++g[i][0]]=j;
			g[j][++g[j][0]]=i;
		}
		pnt[i]=i;
	}
	while (scanf("%c",&s)!=-1)
	{
		if(s=='O')
		{
			scanf(" %d%c",&b,&ch);
			vis[b]=1;
			x=find(b);
			for(i=1;i<=g[b][0];i++)
			if(vis[g[b][i]])
			{
				y=find(g[b][i]);
				if(x!=y)pnt[y]=x;
			}
		}
		else
		{
			scanf(" %d %d%c",&b,&c,&ch);
			x=find(b);y=find(c);
			if(x==y) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;
}