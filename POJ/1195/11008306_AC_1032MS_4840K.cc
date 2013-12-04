#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1034
#define M 10010
int ord,n;
int a[N][N];
int x,y,p,z,w;
int lowbit(int x)
{
	return x & (-x);
}
int sum(int x,int y)
{
	int i,j,ans=0;
	for(i=x;i>0;i-=lowbit(i))
	for(j=y;j>0;j-=lowbit(j))
		ans+=a[i][j];
	return ans;
}
void update(int x,int y,int p)
{
	int i,j;
	for(i=x;i<=n;i+=lowbit(i))
	for(j=y;j<=n;j+=lowbit(j))
		a[i][j]+=p;
}
int main ()
{
	while (scanf("%d",&ord)!=-1 && ord!=3)
	{
		if(ord==0)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				a[i][j]=a[j][i]=0;
		}
		if(ord==1)
		{
			scanf("%d %d %d",&x,&y,&p);
			update(x+1,y+1,p);
		}
		if(ord==2)
		{
			scanf("%d %d %d %d",&x,&y,&z,&w);
			z++,w++;
			printf("%d\n",sum(z,w)+sum(x,y)-sum(x,w)-sum(z,y));
		}
	}
	
	return 0;
}