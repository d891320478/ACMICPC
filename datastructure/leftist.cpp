#define N 100010
struct tree
{	int l,r,f,d,key;	void clear(){l=r=f=-1; d=0;}	}a[N];
int pnt[N];	int n,m;
int iroot(int i)//查找点i的根结点
{	if(i==-1) return i;		while (a[i].f!=-1) i=a[i].f;	return i;	}
int merge(int rx,int ry)//合并两个子树
{
	if(rx==-1) return ry;	if(ry==-1) return rx;
	if(a[rx].key>a[ry].key) swap(rx,ry);
	int r=merge(a[rx].r,ry);	a[rx].r=r; a[r].f=rx;
	if(a[r].d>a[a[rx].l].d) swap(a[rx].l,a[rx].r);
	if(a[rx].r==-1) a[rx].d=0;	else a[rx].d=a[a[rx].r].d+1;
	return rx;
}
int ins(int i,int key,int root)//插入新节点
{	a[i].key=key;	a[i].clear();	return root=merge(root,i);	}
int del(int i)//删除节点
{
	if(i==-1)return i;
	int x,y=a[i].f,l=a[i].l,r=a[i].r;
	a[i].clear();		a[x=merge(l,r)].f=y;
	if(y!=-1 && a[y].l==i) a[y].l=x;	if(y!=-1 && a[y].r==i) a[y].r=x;
	for(;y!=-1;x=y,y=a[y].f)
	{
		if(a[a[y].l].d<a[a[y].r].d) swap(a[y].l,a[y].r);
		if(a[a[y].r].d+1==a[y].d)break;		a[y].d=a[a[y].r].d+1;
	}
	if(x!=-1) return iroot(x);	else return iroot(y);
}
tree top(int root)//取最小节点
{	return a[root];	}
tree pop(int &root)
{
	tree out=a[root];		int l=a[root].l,r=a[root].r;
	a[root].clear();		a[l].f=a[r].f=-1;		root=merge(l,r);	return out;
}
int add(int i,int val)//增加、减小一个节点的值a[i].key+=val
{
	if(i==-1)return i;
	if(a[i].l==-1 || a[i].r==-1 && a[i].f==-1)
	{		a[i].key+=val;		return i;	}
	int key=a[i].key+val;	int rt=del(i);	return ins(i,key,rt);
}
void init()
{
	for(int i=1;i<=n;i++)
	{		scanf("%d",&a[i].key);		a[i].clear();		pnt[i]=i;	}
}
int find(int x)
{	while(x!=pnt[x]) x=pnt[x];	return x;	}
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		init();		scanf("%d",&m);
		while (m--)
		{
			int x,y,px,py,xx,yy,tmp,p;
			scanf("%d%d",&x,&y);
			px=find(x); py=find(y);			pnt[x]=px; pnt[y]=py;
			if(px==py)printf("-1\n");
			else
			{
				a[px].key/=2;		tmp=merge(a[px].l,a[px].r);
				a[px].clear();		xx=merge(tmp,px);
				a[py].key/=2;		tmp=merge(a[py].l,a[py].r);
				a[py].clear();		yy=merge(tmp,py);
				p=merge(xx,yy);
				pnt[x]=pnt[y]=pnt[xx]=pnt[yy]=pnt[px]=pnt[py]=p;
				printf("%d\n",a[p].key);
			}
		}
	}
	return 0;
}
