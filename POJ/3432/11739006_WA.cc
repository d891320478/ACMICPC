#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
	int x,y;
}p[1001],a,b;
int n,i,j,ans;
bool operator==(const point &a,const point &b)
{
	return a.x==b.x && a.y==b.y;
}
bool operator<(const point &a,const point &b)
{
	return a.x<b.x || a.x==b.x && a.y<b.y;
}
bool operator>(const point &a,const point &b)
{
	return a.x>b.x || a.x==b.x && a.y>b.y;
}
bool f(point po)
{
	int s=0,t=n-1,mid;
	while(s<=t)
	{
		mid=(s+t)/2;
		if(p[mid]==po)return 1;
		if(po>p[mid])s=mid+1;
		else t=mid-1;
	}
	return 0;
}
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p+n);
		ans=0;
		for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			a.x=p[i].x+p[i].y-p[j].y;
			a.y=p[i].y-p[i].x+p[j].x;
			b.x=p[j].x+p[i].y-p[j].y;
			b.y=p[j].y-p[i].x+p[j].x;
			if(f(a) && f(b))ans++;
		}
		printf("%d\n",ans/2);
	}
	
	return 0;
}