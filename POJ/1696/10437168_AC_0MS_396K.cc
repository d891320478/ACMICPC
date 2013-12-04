#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
	int x,y,num,dis;
}p[55],a;
int n;
int ans[55];
int dist(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int Cmp_PolarAngel(point p1,point p2,point p0)
{
	int delta=xmult(p1,p2,p0);
	if(delta<0.0)return 1;
	if(delta==0.0)return 0;
	return -1;
}
bool Is_LeftTurn(point p3,point p2,point p1)
{
	int type=Cmp_PolarAngel(p3,p1,p2);
	return type<0;
}
int Cmp(const point &a,const point &b)
{
	int type=Cmp_PolarAngel(a,b,p[0]);
	if(type<0)return 1;
	if(type==0)
		if(a.dis<b.dis)return 1;
		else return 0;
	return 0;
}
int main ()
{
	int t,k;
	scanf("%d",&t);
	while (t--)
	{
		bool f[55]={0};
		scanf("%d",&n);
		scanf("%d%d%d",&p[1].num,&p[1].x,&p[1].y);
		a=p[1]; ans[1]=1;
		for(int i=2;i<=n;i++)
		{
			scanf("%d%d%d",&p[i].num,&p[i].x,&p[i].y);
			if(p[i].y<a.y || (p[i].y==a.y && p[i].x<a.x))
				a=p[i];
		}
		f[1]=f[0]=1;
		p[0]=a; p[0].x=p[0].num=0; p[0].dis=0;
		ans[0]=0; ans[1]=1;
		for(int i=1;i<=n;i++)
			p[i].dis=dist(p[0],p[i]);
		sort(p+1,p+n+1,Cmp);
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				if(! f[j])
				{
					ans[i]=j;
					break;
				}
			for(int j=1;j<=n;j++)
				if(! f[j])
				if(j!=ans[i])
				{
					if(xmult(p[ans[i]],p[j],p[ans[i-1]])<0 || (xmult(p[ans[i]],p[j],p[ans[i-1]])==0 && dist(p[j],p[ans[i-1]])<dist(p[ans[i]],p[ans[i-1]]))) ans[i]=j;
				}
			f[ans[i]]=1;
		}
		printf("%d",n);
		for(int i=1;i<=n;i++)
			printf(" %d",p[ans[i]].num);
		printf("\n");
			
	}
	
	return 0;
}