#define N 5010
#define M N*N
int n,m,step,tot,color;
int dfn[N],low[N],stack[N],vis[N],head[N],next[M],e[M];
bool instack[N];
void dfs(int s)
{
    int i,j;
   	low[s]=dfn[s]=++step;	stack[++tot]=s;	instack[s]=1;
	for(i=head[s];i!=-1;i=next[i])
	{
		if(! dfn[e[i]])
		{	dfs(e[i]);		low[s]=low[s]<low[e[i]]?low[s]:low[e[i]];		}
		else
		if(instack[e[i]])  low[s]=low[s]<dfn[e[i]]?low[s]:dfn[e[i]];
	}
    if(dfn[s]==low[s])
    {
    	color++;
        do{  j=stack[tot--];   instack[j]=0;   vis[j]=color;    }while(j!=s);
    }
}
int main()
{
		step=tot=color=0;
		memset(vis,0,sizeof(vis));		memset(dfn,0,sizeof(dfn));
		for(i=1;i<=n;i++)	if(! dfn[i]) dfs(i);
    return 0;
}
