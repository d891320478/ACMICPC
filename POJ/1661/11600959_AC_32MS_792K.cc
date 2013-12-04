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
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
int fastget()
{
	char c; int ans=0; c=getchar();
	int sign=1;
	while (! (c>='0' && c<='9' || c=='-')) c=getchar();
	if(c=='-') sign=-1,c=getchar();
	while (c>='0' && c<='9')
	{
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans*sign;
}
void fastput(int x)
{
	char s[12]; int a=0;
	if(x==0) puts("0");
	else
	{
		if(x<0) putchar('-'),x=-x;
		while (x) { s[a++]=x%10+'0'; x/=10; }
		for(a--;a>=0;a--) putchar(s[a]);
		putchar('\n');
	}
}
#define N 2020
#define M 100010
int head[N],cnt,s,t;
struct edge
{
	int v,w,next;
}e[M];
void add(int u,int v,int w)
{
	e[cnt].next=head[u];
	e[cnt].v=v;
	e[cnt].w=w;
	head[u]=cnt++;
}
int n,_x,_y,_max;
struct _pt
{
	int x1,x2,h;
}b[N];
queue<int> q;
int d[N],vis[N];
int main()
{
	int tt=fastget();
	while (tt--)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		n=fastget();
		_x=fastget();
		_y=fastget();
		_max=fastget();
		s=0;
		t=2*n+1;
		for(int i=1;i<=n;i++)
		{
			b[i].x1=fastget();
			b[i].x2=fastget();
			b[i].h=fastget();
		}
		int _mh=0,_k=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i].x1<=_x && b[i].x2>=_x)
			if(b[i].h<=_y)
			if(b[i].h>_mh)
			{
				_k=i;
				_mh=b[i].h;
			}
		}
		if(_k==0)
		{
			printf("%d\n",_y);
			continue;
		}
		add(s,_k*2-1,_y-b[_k].h+_x-b[_k].x1);
		add(s,_k*2,_y-b[_k].h-_x+b[_k].x2);
		for(int i=1;i<=n;i++)
		{
			int _ml=0,_mr=0,_kl=0,_kr=0;
			for(int j=1;j<=n;j++)
				if(j!=i)
				if(b[j].h<b[i].h && b[i].h-b[j].h<=_max)
				{
					if(b[i].x1>=b[j].x1 && b[i].x1<=b[j].x2)
					if(_ml<b[j].h)
					{
						_kl=j;
						_ml=b[j].h;
					}
					if(b[i].x2>=b[j].x1 && b[i].x2<=b[j].x2)
					if(_mr<b[j].h)
					{
						_kr=j;
						_mr=b[j].h;
					}
				}
			if(_kl==0)
			{
				if(b[i].h<=_max) add(i*2-1,t,b[i].h);
			}
			else
			{
				add(i*2-1,_kl*2-1,b[i].h-b[_kl].h+b[i].x1-b[_kl].x1);
				add(i*2-1,_kl*2,b[i].h-b[_kl].h-b[i].x1+b[_kl].x2);
			}
			if(_kr==0)
			{
				if(b[i].h<=_max) add(i*2,t,b[i].h);
			}
			else
			{
				add(i*2,_kr*2-1,b[i].h-b[_kr].h+b[i].x2-b[_kr].x1);
				add(i*2,_kr*2,b[i].h-b[_kr].h-b[i].x2+b[_kr].x2);
			}
		}
		/*
		for(int i=0;i<=t;i++)
		{
			printf("_s = %d\n",i);
			for(int j=head[i];j!=-1;j=e[j].next)
				printf("%d %d\n",e[j].v,e[j].w);
		}
		*/
		q.push(s);
		memset(d,-1,sizeof(d));
		memset(vis,0,sizeof(vis));
		d[s]=0;
		while (! q.empty())
		{
			int u=q.front();
			q.pop();
			vis[u]=0;
			for(int i=head[u];i!=-1;i=e[i].next)
				if(d[e[i].v]==-1 || d[e[i].v]>d[u]+e[i].w)
				{
					d[e[i].v]=d[u]+e[i].w;
					if(! vis[e[i].v])
					{
						q.push(e[i].v);
						vis[e[i].v]=1;
					}
				}
		}
		printf("%d\n",d[t]);
	}
	return 0;
}