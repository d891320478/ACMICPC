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
  		{	u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		h[i]=e[j];		return 1;		}
  		}
    return 0;
}
int main()
{
	char s[60][60];
	while(scanf("%ld%ld",&n,&p)!=-1)
	{
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		memset(h,0,sizeof(h));	memset(q,0,sizeof(q));	memset(head,-1,sizeof(head));
		memset(e,0,sizeof(e));	memset(next,0,sizeof(next));
		int cnt=0;
		va=0;
		for(int i=0;i<n;i++)
		for(int j=0;j<p;j++)
		if(s[i][j]=='*')
		{
			int s=i+1,t=j+1;
			next[cnt]=head[s];	e[cnt]=t;	head[s]=cnt++;
			if(! h[s])	if(! q[t])
			{	h[s]=t;	q[t]=s;	va++;	}
		}
		for(int i=1;i<=n;i++)
		if(! h[i])		{	memset(u,0,sizeof(u));	if(dfs(i))va++;	}
		printf("%d\n",va);
	}
	return 0;
}