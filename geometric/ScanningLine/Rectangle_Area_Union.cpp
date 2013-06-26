#define N 1010
int n;	int cnt[N<<2],ls,lx;		double tree[N<<2],area,xa[N];
struct segment{	double l,r,h;	int c;	}s[N];
bool operator < (segment a,segment b)	{	return a.h<b.h;		}
int search(int l,int r,double *a,double x)
{	int mid;
	while (l<=r)
	{	mid=(l+r)>>1;		if(a[mid]==x) return mid;
		if(a[mid]<x) l=mid+1;		else r=mid-1;
	}
}
void push_up(int l,int r,int rt)
{	if(cnt[rt]) tree[rt]=xa[r]-xa[l];
	else if(l+1==r) tree[rt]=0;
	else tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void update(int l,int r,int c,int L,int R,int rt)
{	if(l<=L && r>=R)	{	cnt[rt]+=c;		push_up(L,R,rt);		return;	}
	int m=(L+R)>>1;
	if(l<m) update(l,r,c,L,m,rt<<1);	if(r>m) update(l,r,c,m,R,rt<<1|1);
	push_up(L,R,rt);
}
int main()
{	int tt=0;
	while (scanf("%d",&n) && n)
	{	area=0;		ls=0;
		for(int i=1;i<=n;i++)
		{	double a,b,c,d;
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			xa[++ls]=a;		s[ls]=(segment){a,c,b,1};
			xa[++ls]=c;		s[ls]=(segment){a,c,d,-1};
		}
		sort(xa+1,xa+1+ls);		sort(s+1,s+1+ls);		lx=1;
		for(int i=2;i<=ls;i++) if(xa[i]!=xa[lx]) xa[++lx]=xa[i];
		memset(tree,0,sizeof(tree));		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<ls;i++)	{
			int l=search(1,lx,xa,s[i].l),r=search(1,lx,xa,s[i].r);
			if(l<r)update(l,r,s[i].c,1,lx,1);		area+=tree[1]*(s[i+1].h-s[i].h);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++tt,area);
	}
	return 0;
}
