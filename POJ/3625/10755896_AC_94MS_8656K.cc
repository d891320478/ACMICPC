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
#define N 1010
#define M 10010
int n,m;
struct point
{
	double x,y;
	void init(){scanf("%lf%lf",&x,&y);}
}p[N];
double a[N][N],d[N],value;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		p[i].init();
		for(int j=1;j<i;j++)
			a[i][j]=a[j][i]=sqrt(pow(p[i].x-p[j].x,2.0)+pow(p[i].y-p[j].y,2.0));
	}
	while (m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		a[u][v]=a[v][u]=0;
	}
	value=0.0;
	for(int i=1;i<=n;i++) d[i]=a[1][i];
	d[1]=-1;
	for(int i=1;i<n;i++)
	{
		double mi=1e20;
		int k,j;
		for(j=1;j<=n;j++)
			if (d[j]>=0 && mi>d[j])
			{
				mi=d[j];
				k=j;
			}
		//value=value>d[k]?value:d[k];
		value+=d[k];
		d[k]=-1;
		for(j=1;j<=n;j++)
			if(d[j]>a[k][j]) d[j]=a[k][j];
	}
	printf("%.2f\n",value);
	
	return 0;
}