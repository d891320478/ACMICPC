#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define N 10010
struct point
{
	double x,y;
	void init(){scanf("%lf %lf",&x,&y);}
}p1[N],p2[N];
int n1,n2;
inline double multiply(point a, point b,point o) //叉积
{
	return  (a.x - o.x)*(b.y - o.y) - (b.x - o.x)*(a.y - o.y);
}
inline double dot(point a, point b , point o)  //点积
{
	return (a.x - o.x)*(b.x - o.x) + (a.y - o.y)*(b.y - o.y);
}
inline double getdis(point a, point b) //两个点之间的距离
{
	return sqrt((a.x - b.x)*(a.x - b.x) +(a.y - b.y)*(a.y - b.y));
}
inline double ptol(point a,point b, point d )  // d -  (a,b) ,d到AB的距离
{
	return fabs(multiply(a,d,b))/getdis(a,b);
}
 
double minp2seg(point a, point b,point d) // d 到线段AB的最短距离
{
	double ans;
	//如果经过D点做垂线不能与AB相交,那么只能在AD BD找最短的
	if(dot(a,d,b)*dot(b,d,a) < 0 )  //做点积
		ans = min(getdis(a,d),getdis(b,d));
	else
		ans = ptol(a,b,d);
	return ans;
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
	bool f1 = true, f2 = true;
	point a,b,o;
	ans = getdis(p1[n1],p2[n2]);
	do 
	{
		a = p1[(n1+1)%v1], a.x -= p1[n1].x , a.y -= p1[n1].y;  //向量A
		b = p2[n2] , b.x -= p2[(n2+1)%v2].x , b.y -= p2[(n2+1)%v2].y; 
		o.x = 0, o.y = 0;
		double rot = multiply(a,b,o);
		if(rot < 0)
		{
			ans = min(ans,minp2seg(p2[n2],p2[(n2+1)%v2],p1[n1]));
			n2 = (n2+1)%v2;
			if(n2 == t2) f2 = false;
		}
		else if(rot > 0)
		{
			ans = min(ans,minp2seg(p1[n1],p1[(n1+1)%v1],p2[n2]));
			n1 = (n1+1)%v1;
			if(n1 == t1) f1 = false;
		}
		else
		{
			ans = min(ans,minp2seg(p1[n1],p1[(n1+1)%v1],p2[n2]));
			ans = min(ans,minp2seg(p1[n1],p1[(n1+1)%v1],p2[(n2+1)%v2]));
			ans = min(ans,minp2seg(p2[n2],p2[(n2+1)%v2],p1[n1]));
			ans = min(ans,minp2seg(p2[n2],p2[(n2+1)%v2],p1[(n1+1)%v1]));
			n1 = (n1+1)%v1 , n2 = (n2+1)%v2;
			if(n1 == t1) f1 = false;
			if(n2 == t2) f2 = false;
		}
	} while (f1||f2);
	return ans;
}
int main ()
{
	while (scanf("%d %d",&n1,&n2) && n1+n2)
	{
		for(int i=0;i<n1;i++) p1[i].init();
		for(int i=0;i<n2;i++) p2[i].init();
		printf("%f\n",mindis(p1,n1,p2,n2));
	}
	
	return 0;
}