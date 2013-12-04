#include <cstdio>
#include <algorithm>
using namespace std;
#define N 210
#define M 40010
int pnt[N],id[M],eu[M],ev[M],ew[M];
int n,m,a[N],b[N],poi,i;
int cmp(const int &i,const int &j)
{
	return ew[i]<ew[j];
}
int find(int x)
{
	if(x!=pnt[x])pnt[x]=find(pnt[x]);
	return pnt[x];
}
int main ()
{
	while (scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		poi=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			b[i]-=a[i];
			poi+=(b[i]<0);
			pnt[i]=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			id[i]=i;
			scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
		}
		sort(id,id+m,cmp);
		int j=-1;
		int p,x,y,flag;
		while(poi>0)
		{
			flag=1;
			while(1)
			{
				p=id[++j];
				if(p>=m)
				{
					flag=0;
					break;
				}
				x=find(eu[p]);
				y=find(ev[p]);
				if(x!=y)break;
			}
			if(! flag) break;
			poi-=(b[x]<0)+(b[y]<0);
			b[x]+=b[y];
			poi+=(b[x]<0);
			pnt[y]=x;
		}
		if(poi==0)printf("%d\n",ew[p]);
		else printf("No Solution\n");
	}
	
	return 0;
}
