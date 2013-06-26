//求长度
int n,m,a[NN],b[NN],lc[NN];
int LCIS(int *a,int n,int *b,int m)
{
	memset(lc,0,sizeof(lc));
	int lst;
	for(int i=1;i<=n;i++)
	{
		lst=0;
		for(int j=1;j<=m;j++)
		{
			if(b[j]<a[i] && lc[j]>lc[lst]) lst=j;
			if(b[j]==a[i]) lc[j]=lc[lst]+1;
		}
	}
	int mx=-1;
	for(int i=1;i<=m;i++)
		mx=max(mx,lc[i]);
	return mx;
}
//长度+方案
int n,m,a[NN],b[NN],lc[NN][NN],c[NN][NN];
pair<int,int> LCIS(int *a,int n,int *b,int m)
{
	memset(lc,0,sizeof(lc));
	int lst;
	for(int i=1;i<=n;i++)
	{
		lst=0;
		for(int j=1;j<=m;j++)
		{
			lc[i][j]=lc[i-1][j];
			c[i][j]=j;
			if(b[j]<a[i] && lc[i-1][j]>lc[i-1][lst]) lst=j;
			if(b[j]==a[i])
			{
				lc[i][j]=lc[i-1][lst]+1;
				c[i][j]=lst;
			}
		}
	}
	int mx=-1,bj;
	for(int i=1;i<=m;i++)
		if(mx<lc[n][i])
		{
			mx=lc[n][i];
			bj=i;
		}
	return make_pair(mx,bj);
}
int ans[NN];
void find(int n,int m)
{
	if(m<=0) return;
	if(a[n]==b[m]) ans[++ans[0]]=a[n];
	find(n-1,c[n][m]);
}
pari<int,int> z=LCIS(a,n,b,m);
find(n,z.second);
