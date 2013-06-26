#include<cstdio>
#include<cstring>
#define N 10010
#define M 100010
int n,m;
int d[N],u[M],v[M];
int main()
{
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		d[u[i]]++,d[v[i]]++;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		ans+=d[u[i]]+d[v[i]];
	}
	printf("%d\n",ans);
	return 0;
}
