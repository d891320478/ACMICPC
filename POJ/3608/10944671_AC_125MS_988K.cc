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
		ans = std::min(getdis(a,d),getdis(b,d));
	else
		ans = ptol(a,b,d);
	return ans;
}
double mindis(point c1[] , int v1, point c2[] , int v2)  //两个凸多边形算法标程,凸包c1,顶点数v1,凸包c2,顶点数v2
{
	double ans;
	int n1 = 0,n2 = 0;
	for (int i = 1 ; i < v1 ; i++)
		if(c1[n1].y > c1[i].y)
			n1 = i;
	for (int i = 1 ; i < v2 ; i++)
		if(c2[n2].y < c2[i].y)
			n2 = i;
	int t1 = n1 , t2 = n2;
	bool f1 = true, f2 = true;
	point a,b,o;
	ans = getdis(c1[n1],c2[n2]);
	do 
	{
		a = c1[(n1+1)%v1], a.x -= c1[n1].x , a.y -= c1[n1].y;  //向量A
		b = c2[n2] , b.x -= c2[(n2+1)%v2].x , b.y -= c2[(n2+1)%v2].y; 
		o.x = 0, o.y = 0;
		double rot = multiply(a,b,o);
		if(rot < 0)
		{
			ans = std::min(ans,minp2seg(c2[n2],c2[(n2+1)%v2],c1[n1]));
			n2 = (n2+1)%v2;
			if(n2 == t2) f2 = false;
		}
		else if(rot > 0)
		{
			ans = std::min(ans,minp2seg(c1[n1],c1[(n1+1)%v1],c2[n2]));
			n1 = (n1+1)%v1;
			if(n1 == t1) f1 = false;
		}
		else
		{
			ans = std::min(ans,minp2seg(c1[n1],c1[(n1+1)%v1],c2[n2]));
			ans = std::min(ans,minp2seg(c1[n1],c1[(n1+1)%v1],c2[(n2+1)%v2]));
			ans = std::min(ans,minp2seg(c2[n2],c2[(n2+1)%v2],c1[n1]));
			ans = std::min(ans,minp2seg(c2[n2],c2[(n2+1)%v2],c1[(n1+1)%v1]));
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