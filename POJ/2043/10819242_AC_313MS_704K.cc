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
	int x,y;
	void init(){scanf("%d %d",&x,&y);}
}a[N];
struct line
{
	int s,t;
}p[N];
int l,r;
struct Y
{
	double yl,yr;
}y[N];
int ly,ans,tmp,down;
int operator<(Y a,Y b)
{
	return (a.yl<b.yl) || (a.yl==b.yl && a.yr<b.yr);
}
int main ()
{
	int i,j;
	while (scanf("%d",&n) && n)
	{
		l=INF; r=-INF;
		for(i=0;i<n;i++)
		{
			a[i].init();
			l=min(l,a[i].x);
			r=max(r,a[i].x);
		}
		a[n]=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i].x<a[i+1].x) p[i].s=i,p[i].t=i+1;
			else p[i].s=i+1,p[i].t=i;
		}
		ans=0;
		for(i=l;i<r;i++)
		{
			down=-2100;
			ly=0;
			for(j=0;j<n;j++)
				if(a[p[j].s].x<=i && a[p[j].t].x>i)
				{
					y[ly].yl=(a[p[j].t].y-a[p[j].s].y)*(i-a[p[j].s].x)/(0.0+a[p[j].t].x-a[p[j].s].x)+a[p[j].s].y;
					y[ly].yr=(a[p[j].t].y-a[p[j].s].y)*(i+1-a[p[j].s].x)/(0.0+a[p[j].t].x-a[p[j].s].x)+a[p[j].s].y;
					//printf("%lf %lf\n",y[ly].yl,y[ly].yr);
					ly++;
				}
			//printf("\n");
			sort(y,y+ly);
			int tmp=0;
			for(j=0;j+1<ly;j+=2)
			{
				int t1=(int)ceil(max(y[j+1].yl,y[j+1].yr));
				int t2=(int)floor(min(y[j].yl,y[j].yr));
				tmp+=t1-max(t2,down);
				down=t1;
			}
			if(tmp>0)ans+=tmp;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}