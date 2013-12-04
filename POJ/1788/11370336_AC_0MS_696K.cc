#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 10010
#define MM 10010
struct point{ int x,y; void init(){scanf("%d%d",&x,&y);}};
struct circle{ point o; double r; };
double xmult(point p0,point p1,point p2)
{ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
double dist(point a,point b)
{ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
int cmp1(point a,point b)
{
	return a.x<b.x || a.x==b.x && a.y<b.y;
}
int cmp2(point a,point b)
{
	return a.y<b.y || a.y==b.y && a.x<b.x;
}
int n,ans;
point a[NN];
int main()
{
	while (scanf("%d",&n) && n)
	{
		ans=0;
		for(int i=0;i<n;i++) a[i].init();
		sort(a,a+n,cmp1);
		for(int i=0;i<n;i+=2)
			if(a[i].x==a[i+1].x) ans+=a[i+1].y-a[i].y;
		sort(a,a+n,cmp2);
		for(int i=0;i<n;i+=2)
			if(a[i].y==a[i+1].y) ans+=a[i+1].x-a[i].x;
		printf("The length of the fence will be %d units.\n",ans);
	}
	return 0;
}