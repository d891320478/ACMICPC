#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 510
#define MAXM 250010
int n,m,p,cnt;
int head[MAXN],next[MAXM],e[MAXM],u[MAXN],h[MAXN],q[MAXN],va;
struct people
{
	int h;
	char sex,mu[110],sp[110];
	void init(){scanf("%d %c %s %s",&h,&sex,&mu,&sp);}
}a[MAXN];
int nx,ny;
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
bool f(int i,int j)
{
	if(abs(a[i].h-a[j].h)<=40)
	if(strcmp(a[i].mu,a[j].mu)==0)
	if(strcmp(a[i].sp,a[j].sp)!=0) return 1;
	return 0;
}
int bh[MAXN];
int main()
{
	int tttt,i,j;
	char ch;
	scanf("%d",&tttt);
	while(tttt--)
	{
		memset(h,0,sizeof(h));	memset(q,0,sizeof(q));	memset(head,-1,sizeof(head));
		scanf("%d%c",&n,&ch);
		nx=ny=0;
		va=0;
		cnt=0;
		for(i=1;i<=n;i++) a[i].init();
		for(i=1;i<=n;i++)
		if(a[i].sex=='F')
			for(j=1;j<=n;j++)
				if(a[j].sex=='M')
				if(f(i,j))
				{
					next[cnt]=head[i];
					e[cnt]=j;
					head[i]=cnt++;
					if(! h[i])	if(! q[j])
					{	h[i]=j;	q[j]=i;	va++;	}
				}
		for(int i=1;i<=n;i++)
		if(! h[i])		{	memset(u,0,sizeof(u));	if(dfs(i))va++;	}
		//for(int i=1;i<=n;i++)
			//printf("%d  %d\n",i,h[i]);
			//printf("%d\n",i);
		printf("%d\n",n-va);
	}
	return 0;
}