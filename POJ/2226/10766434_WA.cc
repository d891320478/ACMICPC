#include <cstdio>
#include <cstring>
#define N 1010
#define SET(a,b) memset(a,b,sizeof(a))
int n,m,p,u[N];
int h[N],q[N],va,a[N][N],b[N][N],sa,sb;
int head[N],next[N*N],e[N*N];
char s[N][N];
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
int main()
{
	//freopen("1.in","r",stdin);
	int i,j;
	SET(head,-1); SET(h,0); SET(q,0);
	SET(a,0); SET(b,0);
	sa=sb=0;
	scanf("%d%d",&n,&p);
	va=0;
	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;)
		{
			while (s[i][j]=='.' && j<p)j++;
			if(j>=p) break;
			sa++;
			for(;j<p && s[i][j]=='*';j++) a[i][j]=sa;
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<n;)
		{
			while (s[j][i]=='.' && j<n)j++;
			if(j>=n) break;
			sb++;
			for(;j<n && s[j][i]=='*';j++) b[i][j]=sb;
		}
	}
	int cnt=0;
	for(i=0;i<n;i++)
	for(j=0;j<p;j++)
		if(a[i][j] && b[i][j])
		{
			next[cnt]=head[a[i][j]];
			e[cnt]=b[i][j];
			head[a[i][j]]=cnt++;
		}
	for(int i=1;i<=sa;i++)
	{
		memset(u,0,sizeof(u));
		if(dfs(i))va++;
	}
	printf("%d\n",va);

	return 0;
}