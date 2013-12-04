#include <cstdio>
#include <cstring>

int head[10001],next[100001],e[100001],l[100001];
int i,j,k,n,m;
int lp=-1,path[100001];
void dfs(int x)
{
	for(int i=head[x];i!=-1;i=next[i])
		if(l[i])
		{
			l[i]=0;
			dfs(e[i]);
		}
	path[++lp]=x;
}

int main ()
{
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&j,&k);
		l[i*2]=1;
		next[i*2]=head[j]; head[j]=i*2; e[i*2]=k;
		l[i*2+1]=1;
		next[i*2+1]=head[k]; head[k]=i*2+1; e[i*2+1]=j;
	}
	dfs(1);
	for(i=lp;i>=0;i--)
		printf("%d\n",path[i]);
	
	return 0;
}