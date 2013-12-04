#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 200010
#define INF 1e100
struct point
{
	int flg;
	double x,y;
}p[N];
int n,tmpt[N];
int cmpxy(point a,point b)
{
	return a.x<b.x || a.x==b.x && a.y<b.y;
}
int cmpy(int a,int b)
{
	return p[a].y<p[b].y;
}
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double closest_pair(int l,int r)
{
	double d;
	if(l==r) return INF;
	if(r-l==1) return (p[l].flg==p[r].flg)?(INF):dist(p[l],p[r]);
	int mid=(l+r)>>1;
	double d1=closest_pair(l,mid),d2=closest_pair(mid+1,r);
	d=min(d1,d2);
	int i,j,k=0;
	for(i=l;i<=r;i++)
		if(fabs(p[mid].x-p[i].x)<=d) tmpt[k++]=i;
	sort(tmpt,tmpt+k,cmpy);
	for(i=0;i<k;i++)
	for(j=i+1;j<k && p[tmpt[j]].y-p[tmpt[i]].y<d;j++)
		if(p[tmpt[i]].flg!=p[tmpt[j]].flg)
		d=min(d,dist(p[tmpt[i]],p[tmpt[j]]));
	return d;
}
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) {scanf("%lf %lf",&p[i].x,&p[i].y); p[i].flg=1;}
		for(int i=0;i<n;i++) {scanf("%lf %lf",&p[i+n].x,&p[i+n].y); p[i+n].flg=2;}
		sort(p,p+n+n,cmpxy);
		printf("%.3f\n",closest_pair(0,n+n-1));
	}
	
	return 0;
}