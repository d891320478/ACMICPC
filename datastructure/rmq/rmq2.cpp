//二维RMQ【四维数组】
int mx[M][M][N][N];  int idx[N],p[M];	int n,m,val[N][N];
void init()
{	idx[0]=-1;
	for(int i=1;i<N;i++) idx[i]=idx[i-1]+!(i&(i-1));
	for(int i=0;i<M;i++) p[i]=1<<i;
}
void rmq()
{
	for(int i=1;i<=n;i++)		for(int j=1;j<=m;j++)	mx[0][0][i][j]=val[i][j];
	for(int i=0;p[i]<=n;i++)
	for(int j=0;p[j]<=m;j++)	if(i || j)
	for(int k=1;k+p[i]-1<=n;k++)
	for(int l=1;l+p[j]-1<=m;l++)
		if(i) mx[i][j][k][l]=max(mx[i-1][j][k][l],mx[i-1][j][k+p[i-1]][l]);
		else mx[i][j][k][l]=max(mx[i][j-1][k][l],mx[i][j-1][k][l+p[j-1]]);
}
int query(int x1,int y1,int x2,int y2)
{
	int tx=idx[x2-x1+1],ty=idx[y2-y1+1];
	return max(max(mx[tx][ty][x1][y1],mx[tx][ty][x1][y2-p[ty]+1]),
			 max(mx[tx][ty][x2-p[tx]+1][y1],mx[tx][ty][x2-p[tx]+1][y2-p[ty]+1]));
}
