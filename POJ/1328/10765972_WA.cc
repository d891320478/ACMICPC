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
double d,w;
struct point
{
	double x,y;
	void init(){scanf("%lf%lf",&x,&y);}
}p[N];
int cmp(const point &a,const point &b)
{
	if(a.x<b.x)return 1;
	if(a.x>b.x)return 0;
	if(a.y>b.y)return 1;
	return 0;
}
int main ()
{
	int tttt=0;
	while (scanf("%d%lf",&n,&d))
	{
		if(n==0 && d==0.0)break;
		for(int i=0;i<n;i++)
		{
			p[i].init();
			if(p[i].y<0) p[i].y=-p[i].y;
		}
		sort(p,p+n,cmp);
		//for(int i=0;i<n;i++) printf("%.2f %.2f\n",p[i].x,p[i].y);
		int sum=0,i;
		for(i=0;i<n;i++)
		{
			if(p[i].y>d)break;
			sum++;
			w=p[i].x+sqrt(d*d-p[i].y*p[i].y);
			//printf("%.2f\n",w);
			i++;
			while (i<n)
			{
				if((p[i].x-w)*(p[i].x-w)+p[i].y*p[i].y<=d*d)i++;
				else break;
				//printf("i = %d\n",i);
			}
			i--;
		}
		printf("Casr %d: ",++tttt);
		if(i<n)printf("-1\n");
		else printf("%d\n",sum);
	}
	
	return 0;
}