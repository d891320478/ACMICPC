//姿势1
#define N 110
bool flag[N],a[N][N];
int ans,cnt[N],group[N],m,n,vis[N];
bool dfs(int u,int pos)
{
	int i,j;
	for(i=u+1;i<=n;i++)
	{
		if(cnt[i]+pos<=ans) return 0;
		if(a[u][i])
		{
			for(j=0;j<pos;j++) if(! a[i][vis[j]]) break;
			if(j==pos)
			{
				vis[pos]=i;
				if(dfs(i,pos+1)) return 1;
			}
		}
	}
	if(pos>ans)
	{
		for(i=0;i<pos;i++) group[i]=vis[i];
		ans=pos;
		return 1;
	}
	return 0;
}
void maxclique()
{
	ans=-1;
	for(int i=n;i>0;i--)
	{
		vis[0]=i;
		dfs(i,1);
		cnt[i]=ans;
	}
}
//姿势2
#define N 110
int a[N][N],n,m,ret[N];
void clique(int n,int *u,int a[][N],int size,int &max,int &bb,int *res,int *rr,int *c)
{
	int i,j,vn,v[N];
	if(n)	{
		if(size+c[u[0]]<=max) return;
		for(i=0;i<n+size-max && i<n;i++)	{
			for(j=i+1,vn=0;j<n;j++)	if(a[u[i]][u[j]]) v[vn++]=u[j];
			rr[size]=u[i];	clique(vn,v,a,size+1,max,bb,res,rr,c);
			if(bb) return;
		}
	}
	else if(size>max)
	{	max=size; 	for(i=0;i<size;i++)		res[i]=rr[i];	bb=1;	}
}
int maxclique(int n,int a[][N],int *ret)
{
	int max=0,bb,c[N],i,j;	int vn,v[N],rr[N];
	for(c[i=n-1]=0;i>=0;i--)
	{
		for(vn=0,j=i+1;j<n;j++)		if(a[i][j]) v[vn++]=j;
		bb=0;		rr[0]=i;
		clique(vn,v,a,1,max,bb,ret,rr,c);		c[i]=max;
	}
	return max;
}
