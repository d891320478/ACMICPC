#define N 100010
#define M 20
int n,m;
struct elem
{
	int v,id;
}a[N];
int d[M][N],s[M][N];
bool cmp(elem a,elem b)
{
	return a.v<b.v || a.v==b.v && a.id<=b.id;
}
void build(int dep,int l,int r)
{
	if(l==r) return;
	int mid=l+r>>1;
	int tl=0,tr=0;
	for(int i=l;i<=r;i++)
	{
		if(cmp(a[d[dep][i]],a[mid]))
		{
			d[dep+1][l+tl]=d[dep][i];
			tl++;
		}
		else
		{
			d[dep+1][mid+1+tr]=d[dep][i];
			tr++;
		}
		s[dep][i]=tl;
	}
	build(dep+1,l,mid);
	build(dep+1,mid+1,r);
}
int find(int dep,int l,int r,int L,int R,int k)
{
	if(L==R) return a[d[dep][L]].v;
	int ls=(l==L)?0:s[dep][L-1];
	int rs=s[dep][R];
	int mid=l+r>>1;
	if(rs-ls<k) return find(dep+1,mid+1,r,mid+L-l-ls+1,mid+R-l-rs+1,k-(rs-ls));
	return find(dep+1,l,mid,l+ls,l+rs-1,k);
}
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++) d[0][a[i].id]=i;
		build(0,1,n);
		int l,r,k;
		while (m--)
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",find(0,1,n,l,r,k));
		}
	}
	return 0;
}
