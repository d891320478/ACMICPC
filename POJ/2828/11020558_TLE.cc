#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 200010
#define INF 1<<30
struct SBT
{
	int l,r,key,sz,val;
	void newsbt(int ins,int ins2)
	{		key=ins;	val=ins2;	sz=1;		l=r=0;	}
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
		if(sbt[t].l==0) return;
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
void SBTinsert(int &t,int v,int w)//插入
{
	if(t==0){	t=++la;		sbt[t].newsbt(v,w);		return;	}
	sbt[t].sz++;
	if(v<sbt[t].key) SBTinsert(sbt[t].l,v,w);
	else SBTinsert(sbt[t].r,v,w);
	maintain(t,v>=sbt[t].key);
}
int n,c[N],a[N],b[N],flag;
int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int ans=0;
	while (x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void update(int x)
{
	while(x<=n)
	{
		c[x]++;
		x+=lowbit(x);
	}
}
int search(int x)
{
	int l=x,r=n,mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if(sum(r)-sum(l-1)-(r-l+1)==0) l=mid+1;
		else r=mid;
	}
	return l;
}
void bl(int rt)
{
	if(sbt[rt].l) bl(sbt[rt].l);
	if(! flag) flag=1;
	else printf(" ");
	printf("%d",sbt[rt].val);
	if(sbt[rt].r) bl(sbt[rt].r);
}
int main()
{
	while (scanf("%d",&n)!=-1)
	{
		root=la=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			a[i]++;
		}
		for(int i=n;i>0;i--)
		{
			int x=search(a[i]);
			SBTinsert(root,x,b[i]);
			update(x);
		}
		flag=0;
		bl(root);
		printf("\n");
	}
	
	return 0;
}