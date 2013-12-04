#include <cstdio>
#include <cstring>
#define N 50010
int n,m,pnt[N],sum,d[N];
int find(int x)
{
	if(x==pnt[x]) return x;
	int idx=find(pnt[x]);
	d[x]=(d[x]+d[pnt[x]])%3;
	return pnt[x]=idx;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) pnt[i]=i;
	while (m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(u==2 && v==w)
		{
			sum++;
			continue;
		}
		if(v>n || w>n)
		{
			sum++;
			continue;
		}
		int x=find(v),y=find(w);
		if(x==y) if((u-1+d[y])%3!=d[x]) sum++;
		if(x!=y)
		{
			pnt[x]=y;
			d[x]=(u-1+d[y]-d[x]+6)%3;
		}
	}
	printf("%d\n",sum);
	
	return 0;
}