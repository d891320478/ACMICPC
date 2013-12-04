#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 10001
#define pi 3.141592653
#define MAKE_VECTOR(p1,p2) (struct node){p[p2].x-p[p1].x,p[p2].y-p[p1].y}
struct node
{
	int x,y;
}p[N];
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
inline int xmult(node p1,node p2,node p0)
{
	int ans=(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
	return ans>0?ans:-ans;
}
int isleft(int p1,int p2,int p3)
{
	return crossp(MAKE_VECTOR(p1,p2),MAKE_VECTOR(p2,p3));
}

void convex_hull()
{
	int i,t;
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
	int s=0;
	for(i=0;i+2<np-1;i++)
		s+=xmult(p[h[i+1]],p[h[i+2]],p[h[i]]);
	printf("%d\n",s/100);
}

int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
			scanf("%d %d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		convex_hull();
	}

	return 0;
}