#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 1024
#define pi 3.141592653
#define MAKE_VECTOR(p1,p2) (struct node){p[p2].x-p[p1].x,p[p2].y-p[p1].y}
struct node
{
	int x,y;
}p[N],xa,xb;
int h[N],np;
int d[N*2],top,bot;
int n,L;

int cmp(const node &a,const node &b)
{
	if(a.y<b.y)return 1;
	if(a.y>b.y)return 0;
	if(a.x<b.x)return 1;
	return 0;
}

inline int crossp(node v1,node v2)
{
	return v1.x*v2.y-v2.x*v1.y;
}
int isleft(int p1,int p2,int p3)
{
	return crossp(MAKE_VECTOR(p1,p2),MAKE_VECTOR(p2,p3));
}
inline int mult(node p1,node p2,node p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
void convex_hull()
{
	int i,j,t;
	bot=n-1; top=n; d[top++]=0; d[top++]=1;
	for (i=2;i<n;++i)
	{
		if (isleft(d[top-2],d[top-1],i)!=0) break;
		d[top-1]=i;
	}
	d[bot--]=i; d[top++]=i;
	if (isleft(d[n],d[n+1],d[n+2])<0)
	{
		t=d[n];
		d[n]=d[n+1];
		d[n+1]=t;
	}
	for (++i;i<n;++i)
	{
		if (isleft(d[bot+1],d[bot+2],i)>0 && isleft(d[top-2],d[top-1],i)>0) continue;
		while (isleft(d[top-2],d[top-1],i)<=0) --top;
		d[top++]=i;
		while (isleft(d[bot+1],d[bot+2],i)<=0) ++bot;
		d[bot--]=i;
	}
	for (i=bot+1;i<top;++i) h[i-bot-1]=d[i];
	np=top-bot-1;
	for(i=0;i+1<np;i++)
	{
		int sum=0;
		xa=p[h[i]],xb=p[h[i+1]];
		for(j=0;j<n;j++)
			if(mult(xa,p[j],xb)==0)sum++;
		if(sum<3)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i) scanf("%d %d",&p[i].x,&p[i].y);
		if(n<=5)
		{
			printf("NO\n");
			continue;
		}
		bool flag=1;
		for(int i=0;i+2<n;i++)
			if(mult(p[i],p[i+1],p[i+2]))
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		sort(p,p+n,cmp);
		convex_hull();
	}
	return 0;
}
