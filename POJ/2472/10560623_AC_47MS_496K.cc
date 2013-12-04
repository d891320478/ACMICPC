#include <cstdio>
#include <cstring>

#define N 110
#define M 10010
int n,m,q[N],tail;
int head[N],next[M],e[M];
double l[M],d[N];
bool vis[N];
int main ()
{
	while(scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			head[i]=-1,d[i]=-1;
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			next[i*2]=head[u];
			e[i*2]=v;
			l[i*2]=w*1.0/100.0;
			head[u]=i*2;
			next[i*2+1]=head[v];
			e[i*2+1]=u;
			l[i*2+1]=w*1.0/100.0;
			head[v]=i*2+1;
		}
		tail=0;
		q[0]=1;
		vis[0]=1;
		d[1]=1;
		while(tail>=0)
		{
			int x=q[tail];
			tail--;
			vis[x]=0;
			for(int i=head[x];i!=-1;i=next[i])
			if(d[e[i]]<d[x]*l[i])
			{
				d[e[i]]=d[x]*l[i];
				if(! vis[e[i]])
				{
					vis[e[i]]=1;
					q[++tail]=e[i];
				}
			}
		}
		printf("%f percent\n",d[n]*100.0);
	}
	
	return 0;
}
