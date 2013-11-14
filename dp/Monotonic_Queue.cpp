long long dp[7][N];
long long sum[7][N];
int n,m,kk,l;
deque<pair<int,long long> > q[7];
int main()
{
	scanf("%d%d%d%d",&m,&n,&kk,&l);
	for(int i=1;i<=n;++i)
	{
		sum[i][0]=0;
		for(int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			sum[i][j]=sum[i][j-1]+x;
		}
	}
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=0;
		q[i].push_back(make_pair(0,0));
	}
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
		{
			while(j-q[i].front().first>l) q[i].pop_front();
			dp[i][j]=q[i].front().second+sum[i][j];
		}
		for(int i=1;i<=n;++i)
		for(int k=1;k<=n;++k)
		if(k!=i)
		{
			while(!q[k].empty() && q[k].back().second>=dp[i][j]-sum[k][j]+kk) q[k].pop_back();
			q[k].push_back(make_pair(j,dp[i][j]-sum[k][j]+kk));
		}
	}
	long long mx=dp[1][m];
	for(int i=2;i<=n;++i)
		mx=min(mx,dp[i][m]);
	cout<<mx<<endl;
	return 0;
}
