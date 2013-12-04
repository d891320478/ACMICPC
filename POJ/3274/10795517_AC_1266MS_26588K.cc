#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 100010
#define M 10010
struct fff
{
	int a[32];
	int bj;
}b[N],c[N];
int n,k,i,j,m,ml,mr,ans;
int cmp(fff c,fff d)
{
	for(int i=0;i<k;i++)
	{
		if(c.a[i]>d.a[i])return 0;
		if(c.a[i]<d.a[i])return 1;
	}
	return 1;
}
int cmps(fff c,fff d)
{
	for(int i=0;i<k;i++)
	{
		if(c.a[i]>d.a[i])return -1;
		if(c.a[i]<d.a[i])return 1;
	}
	return 0;
}
int main ()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&k);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if(m==(1<<k)-1) ans=1;
		j=0;
		//printf(" %d\n",m);
		for(j=0;j<k;j++)
		{
			b[i].a[j]=b[i-1].a[j]+(m & 1);
			m>>=1;
		}
		/*for(j=0;j<k;j++)
			printf("%d ",b[i].a[j]);
		printf("\n");*/
		c[i].bj=i;
		for(j=0;j<k;j++)
			c[i].a[j]=b[i].a[j]-b[i].a[0];
		/*for(j=0;j<k;j++)
			printf("%d ",c[i].a[j]);
		printf("\n\n");*/
	}
	//printf("\n");
	sort(c,c+n+1,cmp);
	/*for(i=0;i<=n;i++)
	{
		for(j=0;j<k;j++)
			printf("%d ",c[i].a[j]);
		printf("\n\n");
	}*/
	ml=mr=c[0].bj;
	for(i=1;i<=n;i++)
	{
		if(cmps(c[i],c[i-1])==0)
		{
			ml=min(ml,c[i].bj);
			mr=max(mr,c[i].bj);
		}
		else
		{
			ans=ans>mr-ml?ans:mr-ml;
			ml=mr=c[i].bj;
		}
	}
	ans=ans>mr-ml?ans:mr-ml;
	printf("%d\n",ans);
	
	return 0;
}