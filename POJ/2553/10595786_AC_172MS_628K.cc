#include<stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 5010
#define M N*N
int n,m,step,tot,color;
int dfn[N],low[N],stack[N],vis[N],head[N],next[M],e[M];
bool instack[N];
void dfs(int s)
{
    int i,j;
   	low[s]=dfn[s]=++step;
	stack[++tot]=s;
	instack[s]=1;
	for(i=head[s];i!=-1;i=next[i])
	{
		if(! dfn[e[i]])
		{
			dfs(e[i]);
			low[s]=low[s]<low[e[i]]?low[s]:low[e[i]];
		}
		else
		if(instack[e[i]])
			low[s]=low[s]<dfn[e[i]]?low[s]:dfn[e[i]];
	}
    if(dfn[s]==low[s])
    {
    	color++;
        do{
            j=stack[tot--];
            instack[j]=0;
            vis[j]=color;
        }while(j!=s);
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n) && n)
    {
    	scanf("%d",&m);
    	memset(head,-1,sizeof(head));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&j,&k);
			next[i]=head[j];
			head[j]=i;
			e[i]=k;
		}
		step=tot=color=0;
		memset(vis,0,sizeof(vis));
		memset(dfn,0,sizeof(dfn));
		for(i=1;i<=n;i++)
			if(! dfn[i]) dfs(i);
		int ans[N],out[N];
		memset(out,0,sizeof(out));
		ans[0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=head[i];j!=-1;j=next[j])
				if(vis[i]!=vis[e[j]])out[vis[i]]++;
		}
		for(i=1;i<=color;i++)
			if(out[i]==0)
				for(j=1;j<=n;j++)
					if(vis[j]==i) ans[++ans[0]]=j;
		sort(ans+1,ans+ans[0]+1);
		for(i=1;i<=ans[0];i++)
		{
			printf("%d",ans[i]);
			if(i!=ans[0])printf(" ");
			else printf("\n");
		}
	}
    return 0;
}