#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXM 2010
int n,m;
int head[MAXN],next[MAXM],e[MAXM],u[MAXN],h[MAXN],q[MAXN],va,cnt;
int dfs(int i)
{
    for(int j=head[i];j!=-1;j=next[j])
  		if(! u[e[j]])
  		{	u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		h[i]=e[j];		return 1;		}
  		}
    return 0;
}
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int au[MAXN];
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		memset(h,0,sizeof(h));	memset(q,0,sizeof(q));	memset(head,-1,sizeof(head));
		cnt=0;
		scanf("%d%d",&n,&m);
		va=0;
		for(i=1;i<=m;i++)
		{
			int v;
			scanf("%d%d",&au[i],&v);
			addedge(au[i],i);
			addedge(v,i);
		}
		for(i=1;i<=n;i++)
		{	memset(u,0,sizeof(u));	if(dfs(i))va++;	}
		if(va<n)printf("NO\n");
		else 
		{
			for(i=1;i<=m;i++)
			{
				if(q[i])printf("%d",q[i]);
				else printf("%d",au[i]);
				if(i<m)printf(" ");
				else printf("\n");
			}			
		}
	}
	return 0;
}