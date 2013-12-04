#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200010
#define INF 1<<30
struct SBT
{
	int l,r,key,sz;
	void newsbt(int ins)
	{		key=ins;		sz=1;		l=r=0;	}
}sbt[N*2];
int la,root;
void SBTr(int &x)//右旋
{
	int y=sbt[x].l;
	sbt[x].l=sbt[y].r;		sbt[y].r=x;	sbt[y].sz=sbt[x].sz;
	sbt[x].sz=sbt[sbt[x].l].sz+sbt[sbt[x].r].sz+1;		x=y;
}
void SBTl(int &x)//左旋
{
	int y=sbt[x].r;
	sbt[x].r=sbt[y].l;		sbt[y].l=x;	sbt[y].sz=sbt[x].sz;
	sbt[x].sz=sbt[sbt[x].l].sz+sbt[sbt[x].r].sz+1;		x=y;
}
void maintain(int &t,bool flag)//维护
{
	if(! flag)
	{
		if(sbt[sbt[sbt[t].l].l].sz>sbt[sbt[t].r].sz) SBTr(t);
		else if(sbt[sbt[sbt[t].l].r].sz>sbt[sbt[t].r].sz)
		{			SBTl(sbt[t].l);			SBTr(t);		}
		else return;
	}
	else
	{
		if(sbt[sbt[sbt[t].r].r].sz>sbt[sbt[t].l].sz) SBTl(t);
		else if(sbt[sbt[sbt[t].r].l].sz>sbt[sbt[t].l].sz)
		{			SBTr(sbt[t].r);			SBTl(t);		}
		else return;
	}
	maintain(sbt[t].l,0);		maintain(sbt[t].r,1);
	maintain(t,0);		maintain(t,1);
}
void SBTinsert(int &t,int v)//插入
{
	if(t==0){	t=++la;		sbt[t].newsbt(v);		return;	}
	sbt[t].sz++;
	if(v<sbt[t].key) SBTinsert(sbt[t].l,v);
	else SBTinsert(sbt[t].r,v);
	maintain(t,v>=sbt[t].key);
}
int SBTdel(int &t,int v)//删除
{
	sbt[t].sz--;
	if(v==sbt[t].key || v<sbt[t].key && !sbt[t].l || v>sbt[t].key && !sbt[t].r)
	{
		if(sbt[t].l && sbt[t].r)
		{	int p=SBTdel(sbt[t].l,v);		sbt[t].key=sbt[p].key;	return p;	}
		else
		{	int p=t;	t=sbt[t].l+sbt[t].r;	return p;		}
	}
	else return SBTdel(v<sbt[t].key?sbt[t].l:sbt[t].r,v);
}
int SBTsucc(int t,int v)//比v大的最小值
{
	if(! t) return INF;
	if(v==sbt[t].key) return v;
	if(v<sbt[t].key) return min(sbt[t].key,SBTsucc(sbt[t].l,v));
	return SBTsucc(sbt[t].r,v);
}
struct cow
{
	int a,b;
	void init(){scanf("%d%d",&a,&b);}
}x[N],y[N];
int n,m;
long long ans;
int cmp(cow x,cow y)
{
	return x.b<y.b || x.b==y.b && x.a<y.a;
}
int main()
{
	root=la=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) x[i].init();
	for(int i=1;i<=m;i++) y[i].init();
	sort(x+1,x+1+n,cmp);
	sort(y+1,y+1+n,cmp);
	for(int i=n;i>0;i--)
	{
		while (m && y[m].b>=x[i].b)
		{
			SBTinsert(root,y[m].a);
			m--;
		}
		int rrr=SBTsucc(root,x[i].a);
		if(rrr==INF)
		{
			printf("-1\n");
			return 0;
		}
		ans+=rrr;
		SBTdel(root,rrr);
	}
	cout<<ans<<endl;
	return 0;
}