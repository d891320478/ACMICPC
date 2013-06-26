//二维RMQ【三维数组】
int mn[M][N][N];  int idx[N],p[M];	int n,m,val[N][N];
void init()
{	idx[0]=-1;
	for(int i=1;i<N;i++) idx[i]=idx[i-1]+!(i&(i-1));
	for(int i=0;i<M;i++) p[i]=1<<i;
}
void rmq()
{	int nn=min(n,m);
	for(int k=0;p[k]<=nn;k++)
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	mn[k][i][j]=val[i][j];
	for(int k=1;p[k]<=nn;k++)
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)
	{
		mn[k][i][j]=mn[k-1][i][j];
		if(i+p[k-1]<=n) mn[k][i][j]=min(mn[k][i][j],mn[k-1][i+p[k-1]][j]);
		if(j+p[k-1]<=m) mn[k][i][j]=min(mn[k][i][j],mn[k-1][i][j+p[k-1]]);
		if(i+p[k-1]<=n && j+p[k-1]<=m) mn[k][i][j]=min(mn[k][i][j],mn[k-1][i+p[k-1]][j+p[k-1]]);
	}
}
int query(int x1,int y1,int x2,int y2)
{
	int k=min(idx[x2-x1+1],idx[y2-y1+1]),ans=mn[0][x1][y1];
	for(int i=x1;i<=x2;i+=p[k])
	{
		if(i+p[k]>x2) i=x2-p[k]+1;
		for(int j=y1;j<=y2;j+=p[k])
		{	if(j+p[k]>y2) j=y2-p[k]+1;	ans=min(ans,mn[k][i][j]);	}
	}
	return ans;
}
