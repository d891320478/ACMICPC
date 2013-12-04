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
		int i;
		cin>>r;
		for(i=0;i<3;i++)
		{
			cin>>p[i].x>>p[i].y;
			th[i]=atan2(p[i].y,p[i].x);
			if(th[i]<-EPS)th[i]+=2*PI;
		}
		for(i=0;i<3;i++)
		{
			if(xmult(p[i],p[(i+1)%3])>-EPS && xmult(p[i],p[(i+2)%3])>-EPS)
			{
				double th0=fabs(th[i]-th[(i+1)%3]);
				if(th0>PI) th0=2*PI-th0;
				if(th0<=2.0/3.0*PI)
				{
					double th1=fabs(th[i]-th[(i+2)%3]);
					if(th1>PI) th1=2*PI-th1;
					if(th1<=2.0/3.0*PI)
					{
						//printf("i = %d\n",i);
						break;
					}
				}
			}
		}
		if(i>=3) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}