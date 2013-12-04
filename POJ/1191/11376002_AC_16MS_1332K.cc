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
struct point
{
	double x,y;
	int init(){return scanf("%lf%lf",&x,&y);}
	point operator + (point a)
	{ point ret; ret.x=x+a.x; ret.y=y+a.y; return ret; }
	point operator - (point a)
	{ point ret; ret.x=x-a.x; ret.y=y-a.y; return ret; }
	double operator * (point a) { return x*a.y-y*a.x; }
	double operator ^ (point a) { return x*a.x+y*a.y; }
};
struct circle{ point o; double r; };
struct point3
{
	double x,y,z;
	int init(){return scanf("%lf%lf%lf",&x,&y,&z);}
	point3 operator + (point3 a)
	{ point3 ret; ret.x=x+a.x; ret.y=y+a.y; ret.z=z+a.z; return ret; }
	point3 operator - (point3 a)
	{ point3 ret; ret.x=x-a.x; ret.y=y-a.y; ret.z=z-a.z; return ret; }
	point3 operator * (point3 a)
	{
		point3 ret;
		ret.x=y*a.z-z*a.y; ret.y=z*a.x-x*a.z; ret.z=x*a.y-y*a.x;
		return ret;
	}
	double operator ^ (point3 a){ return x*a.x+y*a.y+z*a.z;  }
};
double xmult(point p0,point p1,point p2)
{ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
point3 xmult3(point3 p0,point3 p1,point3 p2)
{
	point3 ret;
	ret.x=(p1.y-p0.y)*(p2.z-p0.z)-(p1.z-p0.z)*(p2.y-p0.y);
	ret.y=(p1.z-p0.z)*(p2.x-p0.x)-(p1.x-p0.x)*(p2.z-p0.z);
	ret.z=(p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
	return ret;
}
double dot(point a,point b){ return a.x*b.x+a.y*b.y; }
double dot3(point3 a,point3 b){ return a.x*b.x+a.y*b.y+a.z*b.z; }
double dist(point a,point b)
{ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
double dist3(point3 a,point3 b)
{ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)); }
int n;
int a[10][10],sum[10][10];
int dp[17][10][10][10][10];
int dfs(int k,int x1,int y1,int x2,int y2)
{
	if(dp[k][x1][y1][x2][y2]) return dp[k][x1][y1][x2][y2];
	if(k==1)
	{
		int r1=sum[x2][y2]+sum[x1-1][y1-1]-sum[x2][y1-1]-sum[x1-1][y2];
		return dp[k][x1][y1][x2][y2]=r1*r1;
	}
	int ans=INF;
	for(int i=x1+1;i<=x2;i++)
	{
		ans=min(ans,dfs(k-1,x1,y1,i-1,y2)+dfs(1,i,y1,x2,y2));
		ans=min(ans,dfs(k-1,i,y1,x2,y2)+dfs(1,x1,y1,i-1,y2));
	}
	for(int i=y1+1;i<=y2;i++)
	{
		ans=min(ans,dfs(k-1,x1,y1,x2,i-1)+dfs(1,x1,i,x2,y2));
		ans=min(ans,dfs(k-1,x1,i,x2,y2)+dfs(1,x1,y1,x2,i-1));
	}
	return dp[k][x1][y1][x2][y2]=ans;
}
double avg,s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=8;i++)
	for(int j=1;j<=8;j++)
	{
		scanf("%d",&a[i][j]);
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		s+=a[i][j];
	}
	avg=s/n;
	//printf("%.3f\n",avg);
	memset(dp,0,sizeof(dp));
	dfs(n,1,1,8,8);
	printf("%.3f\n",sqrt(dp[n][1][1][8][8]*1.0/n-avg*avg));
	
	return 0;
}