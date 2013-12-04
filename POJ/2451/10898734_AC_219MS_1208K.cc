#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 20010
#define EPS 1e-10
struct point
{
	double x,y;
	void init(){scanf("%lf%lf",&x,&y);}
}poi[N];
struct line
{
	point s,e;
	double k;
}L[N];
int n,que[N];
double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool operator < (line a,line b)
{
	if(fabs(a.k-b.k)<EPS) return xmult(b.s,b.e,a.s)<0;
	return a.k<b.k;
}
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
double halflnsec()
{
	int i,j,k,l;
	sort(L,L+n);
	for(i=1,j=0;i<n;i++)
		if(fabs(L[i].k-L[j].k)>EPS) L[++j]=L[i];
	n=j+1;
	k=0;l=1;
	que[0]=0;que[1]=1;
	poi[1]=intersection(L[0].s,L[0].e,L[1].s,L[1].e);
	for(i=2;i<n;i++)
	{
		while (k<l && xmult(L[i].s,L[i].e,poi[l])>EPS) l--;
		while (k<l && xmult(L[i].s,L[i].e,poi[k+1])>EPS) k++;
		que[++l]=i;
		poi[l]=intersection(L[que[l-1]].s,L[que[l-1]].e,L[i].s,L[i].e);
	}
	while (k<l && xmult(L[que[k]].s,L[que[k]].e,poi[l])>EPS) l--;
	while (k<l && xmult(L[que[l]].s,L[que[l]].e,poi[k+1])>EPS) k++;
	poi[k]=intersection(L[que[l]].s,L[que[l]].e,L[que[k]].s,L[que[k]].e);
	poi[++l]=poi[k];
	double s=0;
	for(i=k;i<l;i++) s+=poi[i].x*poi[i+1].y-poi[i].y*poi[i+1].x;
	return fabs(s/2.0);
}
int main ()
{
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		L[i].e.init(); L[i].s.init();
	}
	L[n].s.x=0; L[n].s.y=0;
	L[n+1].s.x=10000; L[n+1].s.y=0;
	L[n+2].s.x=10000; L[n+2].s.y=10000;
	L[n+3].s.x=0; L[n+3].s.y=10000;
	L[n].e=L[n+3].s;
	L[n+1].e=L[n].s;
	L[n+2].e=L[n+1].s;
	L[n+3].e=L[n+2].s;
	n+=4;
	for(i=0;i<n;i++)
		L[i].k=atan2(L[i].s.y-L[i].e.y,L[i].s.x-L[i].e.x);
	printf("%.1f\n",halflnsec());
	
	return 0;
}