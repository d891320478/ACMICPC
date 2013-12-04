#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 1000010
#define INF 1<<30
struct SBT
{
	int l,r,key,sz,id;
	void newsbt(int ins,int idx)
	{		key=ins;	id=idx;	sz=1;	l=r=0;	}
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
void SBTinsert(int &t,int v,int d)//插入
{
	if(t==0){	t=++la;		sbt[t].newsbt(v,d);		return;	}
	sbt[t].sz++;
	if(v<sbt[t].key) SBTinsert(sbt[t].l,v,d);
	else SBTinsert(sbt[t].r,v,d);
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
int maxs(int t)
{
	int x=t;
	while (sbt[x].r) x=sbt[x].r;
	return x;
}
int mins(int t)
{
	int x=t;
	while (sbt[x].l) x=sbt[x].l;
	return x;
}
int main()
{
	root=la=0;
	int cz;
	while (scanf("%d",&cz) && cz)
	{
		if(cz==1)
		{
			int p,k;
			scanf("%d%d",&k,&p);
			SBTinsert(root,p,k);
		}
		if(cz==2)
		{
			if(root==0)printf("0\n");
			else
			{
				int t=maxs(root);
				printf("%d\n",sbt[t].id);
				SBTdel(root,sbt[t].key);
			}
		}
		if(cz==3)
		{
			if(root==0)printf("0\n");
			else
			{
				int t=mins(root);
				printf("%d\n",sbt[t].id);
				SBTdel(root,sbt[t].key);
			}
		}
	}
	return 0;
}