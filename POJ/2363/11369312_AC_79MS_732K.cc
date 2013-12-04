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
struct point{ double x,y; void init(){scanf("%lf%lf",&x,&y);}};
double xmult(point p0,point p1,point p2)
{ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
double dist(point a,point b)
{ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
int n;
int a[NN];
int main()
{
	int tt;
	memset(a,0x7f,sizeof(a));
	for(int i=1;i<=1000;i++)
	for(int j=1;j<=i;j++)
	for(int k=1;k<=j && j*k<=i;k++)
	if(i%(j*k)==0)
		a[i]=min(a[i],2*(j*k+j*(i/j/k)+k*(i/j/k)));
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}