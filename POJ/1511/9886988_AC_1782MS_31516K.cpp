#include <cstdio>
#include <cstring>
#include <queue>
#define maxe 1000010
#define maxv 1000010
#define inf 2000000000
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;

int t;
long n,m;
long u[maxe],v[maxe],w[maxe],first[maxe],next[maxe],inq[maxv];
long long d[maxv],ans;

void spfa(long s,long *v)
{
	queue<long> q;
	long x;

	for(long i=1;i<=n;i++)
	{
		d[i]=inf;
		inq[i]=0;
	}
	d[s]=0;
	inq[s]=1;
	q.push(s);
	while (! q.empty())
	{
		x=q.front(); q.pop();
		inq[x]=0;
		for(int i=first[x];i!=-1;i=next[i])
		{
			if(d[x]+w[i]<d[v[i]])
			{
				d[v[i]]=d[x]+w[i];
				if(! inq[v[i]])
				{
					inq[v[i]]=1;
                	q.push(v[i]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans+=d[i];
}

int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%ld%ld",&n,&m);
		memset(first,-1,sizeof(first));
		for(int i=0;i<m;i++)
		{
			scanf("%ld%ld%ld",&u[i],&v[i],&w[i]);
			next[i]=first[u[i]];
        	first[u[i]]=i;
		}
		ans=0;
		spfa(1,v);
		memset(first,-1,sizeof(first));
		for(int i=0;i<m;i++)
		{
			next[i]=first[v[i]];
        	first[v[i]]=i;
		}
		spfa(1,u);
		printf("%lld\n",ans);
	}
	
	return 0;
}