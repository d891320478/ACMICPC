#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 20
#define pi 3.141592653
#define MAKE_VECTOR(p1,p2) (struct node){p[p2].x-p[p1].x,p[p2].y-p[p1].y}
struct node
{
	int x,y;
}p[N],q[N];
int v[N],u[N],ans[N],vsum,vt;
double l[N],lsum,lt,lans;
int h[N],np;
int d[N*2],top,bot;
int n,nn;
int cmp(const node &a,const node &b)
{
	if(a.y<b.y)return 1;
	if(a.y>b.y)return 0;
	if(a.x<b.x)return 1;
	return 0;
}
inline int crossp(struct node v1,struct node v2)
{
	return v1.x*v2.y-v2.x*v1.y;
}
int isleft(int p1,int p2,int p3)
{
	return crossp(MAKE_VECTOR(p1,p2),MAKE_VECTOR(p2,p3));
}
double lll(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
	if(n>=3)
	{
		lsum=0.0;
		for(i=0;i<np-1;i++)
			lsum+=lll(p[h[i]],p[h[i+1]]);
	}
	if(n<=1)lsum=0.0;
	if(n==2)lsum=2*lll(p[0],p[1]);
	if(lsum<=lt)
	{
		lans=lt-lsum;
		vt=vsum;
		ans[0]=0;
		for(i=1;i<=nn;i++)
			if(u[i])ans[++ans[0]]=i;
	}
}
int main()
{
	int cases=1;
	while (scanf("%d",&nn) && nn)
	{
		for (int i=1;i<=nn;++i) scanf("%d%d%d%lf",&q[i].x,&q[i].y,&v[i],&l[i]);
		vt=1000000000;
		for(int i=1;i<=1<<nn;i++)
		{
			int j=i;
			n=0; vsum=0.0; lt=0.0;
			for(int k=1;k<=nn;k++)
			{
				u[k]=j%2;
				j/=2;
				if(! u[k]) p[n++]=q[k];
				else lt+=l[k],vsum+=v[k];
			}
			if(vsum<vt || (vsum==vt && (nn-n<ans[0] || ans[0]==0)))
			{
				sort(p,p+n,cmp);
				convex_hull();
			}
		}
		if(cases>1)printf("\n");
		printf("Forest %d\nCut these trees:",cases);
		for(int i=1;i<=ans[0];i++)
			printf(" %d",ans[i]);
		printf("\nExtra wood: %.2lf\n",lans);
		cases++;
	}
	return 0;
}