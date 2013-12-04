#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;
#define N 50010
#define INF 1<<30
struct SBT
{
	int l,r,key,sz;
	void newsbt(int ins)
	{
		key=ins;
		sz=1;
		l=r=0;
	}
}sbt[N*2];
int la,root;
void SBTr(int &x)//右旋
{
	int y=sbt[x].l;
	sbt[x].l=sbt[y].r;
	sbt[y].r=x;
	sbt[y].sz=sbt[x].sz;
	sbt[x].sz=sbt[sbt[x].l].sz+sbt[sbt[x].r].sz+1;
	x=y;
}
void SBTl(int &x)//左旋
{
	int y=sbt[x].r;
	sbt[x].r=sbt[y].l;
	sbt[y].l=x;
	sbt[y].sz=sbt[x].sz;
	sbt[x].sz=sbt[sbt[x].l].sz+sbt[sbt[x].r].sz+1;
	x=y;
}
int SBTsearch(int t,int key)
{
	if(t==0 || sbt[t].key==key) return t;
	if(key<sbt[t].key) return SBTsearch(sbt[t].l,key);
	else return SBTsearch(sbt[t].r,key);
}
void maintain(int &t,bool flag)//维护
{
	if(! flag)
	{
		if(sbt[t].l==0) return;
		if(sbt[sbt[sbt[t].l].l].sz>sbt[sbt[t].r].sz) SBTr(t);
		else if(sbt[sbt[sbt[t].l].r].sz>sbt[sbt[t].r].sz)
		{
			SBTl(sbt[t].l);
			SBTr(t);
		}
		else return;
	}
	else
	{
		if(sbt[sbt[sbt[t].r].r].sz>sbt[sbt[t].l].sz) SBTl(t);
		else if(sbt[sbt[sbt[t].r].l].sz>sbt[sbt[t].l].sz)
		{
			SBTr(sbt[t].r);
			SBTl(t);
		}
		else return;
	}
	maintain(sbt[t].l,0);
	maintain(sbt[t].r,1);
	maintain(t,0);
	maintain(t,1);
}
void SBTinsert(int &t,int v)//插入
{
	if(t==0)
	{
		t=++la;
		sbt[t].newsbt(v);
		return;
	}
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
		{
			int p=SBTdel(sbt[t].l,v);
			sbt[t].key=sbt[p].key;
			return p;
		}
		else
		{
			int p=t;
			t=sbt[t].l+sbt[t].r;
			return p;
		}
	}
	else return SBTdel(v<sbt[t].key?sbt[t].l:sbt[t].r,v);
}
int SBTpred(int t,int v)//比v小的最大值
{
	if(!t) return -1;
	if(v<=sbt[t].key) return SBTpred(sbt[t].l,v);
	else return max(sbt[t].key,SBTpred(sbt[t].r,v));
}
int SBTsucc(int t,int v)//比v大的最小值
{
	if(!t) return INF;
	if(v>=sbt[t].key) return SBTsucc(sbt[t].r,v);
	else return min(sbt[t].key,SBTsucc(sbt[t].l,v));
}
int SBTselect(int t,int k)//以t为根的树的第k大数
{
	if(k==sbt[sbt[t].l].sz+1) return sbt[t].key;
	if(k<=sbt[sbt[t].l].sz) return SBTselect(sbt[t].l,k);
	else return SBTselect(sbt[t].r,k-1-sbt[sbt[t].l].sz);
}
int SBTrank(int t,int key)//key是以t为根的第几大数
{
	if(t==0) return 1;
	if(key<=sbt[t].key) return SBTrank(sbt[t].l,key);
	else return sbt[sbt[t].l].sz+1+SBTrank(sbt[t].r,key);
}
int n,m;
stack<int> q;
char ch,a;
int b;
int main ()
{
	scanf("%d%d%c",&n,&m,&ch);
	root=la=0;
	SBTinsert(root,0);
	SBTinsert(root,n+1);
	while (m--)
	{
		scanf("%c",&a);
		if(a=='R')
		{
			if(! q.empty())
			{
				SBTdel(root,q.top());
				q.pop();
			}
		}
		else if(a=='D')
		{
			scanf("%d",&b);
			q.push(b);
			SBTinsert(root,b);
		}
		else
		{
			scanf("%d",&b);
			if(SBTsearch(root,b))printf("0\n");
			else
			//printf("%d %d\n",SBTsucc(root,b),SBTpred(root,b));
			printf("%d\n",SBTsucc(root,b)-SBTpred(root,b)-1);
		}
		getchar();
	}
	return 0;
}