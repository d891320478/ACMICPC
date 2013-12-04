#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define INF 1<<30
#define SET(a,b) memset(a,b,sizeof(a))
int n,m;
int a[510][510],ans,d[510],v[510];
bool vis[510];
int stoer_wagner(int n)
{
	int i,j;
	ans=INF;
	for(i=0;i<n;i++) v[i]=i;
	while (n>1)
	{
		int k=1,pre=0;
		for(i=1;i<n;i++)
		{
			d[v[i]]=a[v[0]][v[i]];
			if(d[v[i]]>d[v[k]]) k=i;
		}
		SET(vis,0);
		for(i=1;i<n;i++)
		{
			if(i==n-1)
			{
				ans=min(ans,d[v[k]]);
				for(j=0;j<n;j++)
				{
					a[v[pre]][v[j]]+=a[v[j]][v[k]];
					a[v[j]][v[pre]]+=a[v[j]][v[k]];
				}
				v[k]=v[--n];
			}
			vis[v[k]]=true;
			pre=k;
			k=-1;
			for(j=1;j<n;j++)
				if(! vis[v[j]])
				{
					d[v[j]]+=a[v[pre]][v[j]];
					if(k==-1 || d[v[k]]<d[v[j]]) k=j;
				}
		}
	}
	return ans;
}
int main ()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		SET(a,0);
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			a[u][v]+=w;
			a[v][u]+=w;
		}
		printf("%d\n",stoer_wagner(n));
	}
	
	return 0;
}