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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
double r;
struct point
{
	double x,y;
}p[3];
double th[3];
double xmult(point p1,point p2)
{
	return p1.x*p2.y-p1.y*p2.x;
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		int i,flag=1;
		cin>>r;
		for(i=0;i<3;i++)
		{
			cin>>p[i].x>>p[i].y;
			if(fabs(p[i].x)<EPS && fabs(p[i].y)<EPS) flag=0;
			th[i]=atan2(p[i].y,p[i].x);
			if(th[i]<-EPS)th[i]+=2*PI;
		}
		if(flag==0)
		{
			cout<<"No\n";
			continue;
		}
		double th0=fabs(th[0]-th[1]),th1=fabs(th[1]-th[2]),th2=fabs(th[0]-th[2]);
		if(th0>PI) th0=2*PI-th0;
		if(th1>PI) th1=2*PI-th1;
		if(th2>PI) th2=2*PI-th2;
		if(th1<2.0/3.0*PI && th0<2.0/3.0*PI && th2<2.0/3.0*PI)
			cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}