#include <cstdio>
#include <cstring>
#define MAXN 50010
#define MAXM 150010
long n,m,p;
long head[MAXN],next[MAXM],e[MAXM],u[MAXN],h[MAXN],q[MAXN],va;

int dfs(int i)
{
    for(int j=head[i];j!=0;j=next[j])
  		if(! u[e[j]])
  		{
   			u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{
    	    	q[e[j]]=i;
    			h[i]=e[j];
    			return 1;
   			}
  		}
    return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(h,0,sizeof(h));
		memset(q,0,sizeof(q));
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(e));
		memset(next,0,sizeof(next));
		scanf("%ld%ld",&n,&p);
		va=0;
		for(int i=1;i<=p;i++)
		{
			long s,t;
			scanf("%ld%ld",&s,&t);
			next[i]=head[s];
			head[s]=i;
			e[i]=t;
			if(! h[s])
			if(! q[t])
			{
				h[s]=t;
				q[t]=s;
				va++;
			}
		}
		for(int i=1;i<=n;i++)
		if(! h[i])
		{
			memset(u,0,sizeof(u));
			if(dfs(i))va++;
		}
		printf("%d\n",n-va);
	}

	return 0;
}
