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
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
struct point
{
	double x,y;
}l[N],r[N],h1,h2,p1,p2;
struct segment
{
	double l,r;
}a[N];
int n,m,la;
double ans;
point intersect(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
int cmp(segment a,segment b)
{
	return a.l<b.l;
}
int main()
{
	double aa,bb,cc;
	while (scanf("%lf%lf%lf",&aa,&bb,&cc))
	{
		if(aa==0.0 && bb==0.0 && cc==0.0) break;
		h1.x=aa; h2.x=bb; h1.y=h2.y=cc;
		scanf("%lf%lf%lf",&p1.x,&p2.x,&p1.y);
		p2.y=p1.y;
		scanf("%d",&n);
		la=m=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&aa,&bb,&cc);
			if(cc<h1.y && cc>p1.y)
			{
				l[m].x=aa; r[m].x=bb;
				l[m].y=r[m].y=cc;
				m++;
			}
		}
		for(int i=0;i<m;i++)
		{
			point lx=intersect(p1,p2,h2,l[i]);
			point rx=intersect(p1,p2,h1,r[i]);
			if(lx.x>=p2.x || rx.x<=p1.x) continue;
			a[la].l=max(lx.x,p1.x);
			a[la].r=min(rx.x,p2.x);
			la++;
		}
		if(! la)
		{
			printf("%.2f\n",p2.x-p1.x);
			continue;
		}
		sort(a,a+la,cmp);
		ans=a[0].l-p1.x;
		double l=a[0].l,r=a[0].r;
		for(int i=1;i<la;i++)
			if(a[i].l>=l && a[i].l<=r) r=max(r,a[i].r);
			else
			{
				ans=max(ans,a[i].l-r);
				l=a[i].l,r=a[i].r;
			}
		ans=max(ans,p2.x-r);
		if(ans<EPS) printf("No View\n");
		else printf("%.2f\n",ans);
	}
	return 0;
}