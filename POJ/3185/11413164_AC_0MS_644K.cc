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
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
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
struct matrix
{
	int n; int a[NN][NN];
	void clear(){ memset(a,0,sizeof(a)); }
	void init(){ clear(); for(int i=1;i<=n;i++) a[i][i]=1; }
	matrix operator * (matrix b)
	{
		matrix c; c.n=n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			c.a[i][j]=0;
			for(int k=1;k<=n;k++) c.a[i][j]+=a[i][k]*b.a[k][j];
		}
		return c;
	}
	matrix operator + (matrix b)
	{
		matrix c; c.n=n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c.a[i][j]=a[i][j]+b.a[i][j];
		return c;
	}
};
int fastget()
{
	char c; int ans=0; c=getchar();
	while (! (c>='0' && c<='9')) c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
int a[NN][NN];
int guass(int a[][NN],int n,int m)
{
	int i,j,k,r;
	for(i=r=1;i<m;i++)
	{
		for(j=r;j<=n && ! a[j][i];j++);
		if(j>n) continue;
		if(j>r) for(k=1;k<=m;k++) swap(a[r][k],a[j][k]);
		for(j=1;j<=n;j++) if(j!=r && a[j][i])
		for(k=i;k<=m;k++) if(a[r][k]) a[j][k]^=1;
		++r;
	}
	return r-1;
}
int main ()
{
	for(int i=1;i<=20;i++)
	{
		a[i][i]=1;
		if(i-1>0) a[i][i-1]=1;
		if(i+1<21) a[i][i+1]=1;
		a[i][21]=fastget();
	}
	int rank=guass(a,20,21);
	if(rank==20)
	{
		int ans=0;
		for(int i=1;i<=20;i++) ans+=a[i][21];
		fastput(ans);
		return 0;
	}
	int ans=21,x[22],sum,vis[22];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=20;i++)
	for(static int j=1;j<=20;j++)
		if(a[i][j])
		{
			vis[j]=i;
			break;
		}
	for(int i=0;i<=1<<(19-rank);i++)
	{
		sum=0;
		int k=i;
		for(int j=1;j<=20;j++)
		if(! vis[j])
		{
			x[j]=k & 1;
			k>>=1;
		}
		for(int j=20;j>0;j--)
		if(vis[j])
		{
			x[j]=a[vis[j]][21];
			for(int k=j+1;k<=20;k++)
				x[j]^=(x[k] && a[vis[j]][k]);
		}
		for(int j=1;j<=20;j++) sum+=x[j];
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}