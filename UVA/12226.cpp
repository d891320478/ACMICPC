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
#define N 10010
#define M 10010
int n;
struct point
{
	int x,y,id;
	void init(int i){ scanf("%d%d",&x,&y); id=i; }
}p[N],a;
int dist(point a,point b) 
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int xmult(point a,point b)
{
	return (a.x-p[0].x)*(b.y-p[0].y)-(b.x-p[0].x)*(a.y-p[0].y);
}
int cmp(point a,point b)
{
	int tmp=xmult(a,b);
	if(tmp>0)return 1;
	if(tmp<0)return 0;
	return dist(a,p[0])<dist(b,p[0]);
}
int main ()
{
	int tttt,i,j;
	scanf("%d",&tttt);
	while (tttt--)
	{
		scanf("%d",&n);
		p[0].init(0);
		a=p[0];
		for(i=1;i<n;i++)
		{
			p[i].init(i);
			if(p[i].x<a.x || p[i].x==a.x && p[i].y<a.y) a=p[i];
		}
		swap(p[0],p[a.id]);
		sort(p+1,p+n,cmp);
		for(i=n-1;i>=1;i--)
			if(xmult(p[i],p[i-1])) break;
		j=n-1;
		for(;i<j;j--,i++)
			swap(p[j],p[i]);
		for(i=0;i<n;i++)
		{
			printf("%d",p[i].id);
			if(i<n-1)printf(" ");
			else printf("\n");
		}
	}
	
	return 0;
}
