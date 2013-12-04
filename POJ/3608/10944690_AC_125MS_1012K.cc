#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define N 10010
struct point
{
	double x,y;
}p1[N],p2[N];
int n1,n2;
inline double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline double dot(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
inline double dist(point a,point b)
{
	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}
inline double ptol(point a,point b,point d)//d到直线ab的距离
{
	return fabs(xmult(a,d,b))/dist(a,b);
}
inline double ptos(point a,point b,point d)//d到线段ab的距离
{
	if(dot(a,d,b)*dot(b,d,a)<0) return min(dist(a,d),dist(b,d));
	else return ptol(a,b,d);
}
double mindis(point p1[] , int v1, point p2[] , int v2)  //两个凸多边形算法标程,凸包p1,顶点数v1,凸包p2,顶点数v2
{
	double ans;
	int n1 = 0,n2 = 0;
	for (int i = 1 ; i < v1 ; i++)
		if(p1[n1].y > p1[i].y)
			n1 = i;
	for (int i = 1 ; i < v2 ; i++)
		if(p2[n2].y < p2[i].y)
			n2 = i;
	int t1 = n1 , t2 = n2;
	bool f1 = 1, f2 = 1;
	point a,b,o;
	ans = dist(p1[n1],p2[n2]);
	do 
	{
		a = p1[(n1+1)%v1], a.x -= p1[n1].x , a.y -= p1[n1].y;  //向量A
		b = p2[n2] , b.x -= p2[(n2+1)%v2].x , b.y -= p2[(n2+1)%v2].y; 
		o.x = 0, o.y = 0;
		double rot = xmult(a,b,o);
		if(rot < 0)
		{
			ans = min(ans,ptos(p2[n2],p2[(n2+1)%v2],p1[n1]));
			n2 = (n2+1)%v2;
			if(n2 == t2) f2 = 0;
		}
		else if(rot > 0)
		{
			ans = min(ans,ptos(p1[n1],p1[(n1+1)%v1],p2[n2]));
			n1 = (n1+1)%v1;
			if(n1 == t1) f1 = 0;
		}
		else
		{
			ans = min(ans,ptos(p1[n1],p1[(n1+1)%v1],p2[n2]));
			ans = min(ans,ptos(p1[n1],p1[(n1+1)%v1],p2[(n2+1)%v2]));
			ans = min(ans,ptos(p2[n2],p2[(n2+1)%v2],p1[n1]));
			ans = min(ans,ptos(p2[n2],p2[(n2+1)%v2],p1[(n1+1)%v1]));
			n1 = (n1+1)%v1 , n2 = (n2+1)%v2;
			if(n1 == t1) f1 = 0;
			if(n2 == t2) f2 = 0;
		}
	} while (f1||f2);
	return ans;
}
int main ()
{
	while (scanf("%d %d",&n1,&n2) && n1+n2)
	{
		for(int i=0;i<n1;i++) scanf("%lf %lf",&p1[i].x,&p1[i].y);
		for(int i=0;i<n2;i++) scanf("%lf %lf",&p2[i].x,&p2[i].y);
		printf("%f\n",mindis(p1,n1,p2,n2));
	}
	
	return 0;
}