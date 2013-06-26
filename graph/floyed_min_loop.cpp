最小环——floyed
#define N 110
#define Max 1000000000
int n,m;//顶点数和边数 
int dist[N][N];//用来记录最短路径 
int map[N][N];//记录边的情况 
int r[N][N];//记录从i到j的最后的一个中间节点 
int out[N];//记录最小环 
int outnum;//最小环的顶点数 
void solve(int i,int j,int k)
{
	outnum=0;
	while(j!=i)
	{	out[outnum++]=j;	j=r[i][j];		}	
	out[outnum++]=i;
	out[outnum++]=k;//最小环的记录顺序是从k-i-----j的，
	//当是求有向路的最小环时要和后面边的书写方向对应上 
}
int main()
{
	int i,j,k;	int a,b,c;	int min;
	while(scanf("%d%d",&n,&m)!=EOF)//顶点数和边数 
	{
		for(i=1;i<=n;i++)	for(j=1;j<=n;j++)
			{
				r[i][j]=i;
				map[i][j]=Max;//因为没有点到自己的边，所以i==j时也是无穷大,而且这也是保证环最少有3个点的要求 
			}//当允许（对于有向和无向图）有两个点的环时可以设map【i】【i】=0； 
		for(i=1;i<=m;i++)	
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c<map[a][b])//解决由重边的情况 
			{	map[a][b]=c;		map[b][a]=c;		}	
		}
		for(i=1;i<=n;i++)	for(j=1;j<=n;j++)	dist[i][j]=map[i][j];
		min=Max;//找最小环 
		for(k=1;k<=n;k++)
		{
			for(i=1;i<k;i++)
			{
				if(map[k][i]<Max)//优化 
					for(j=i+1;j<k;j++)//当为有向时就需要这里也从j=1开始 
					{
						if(map[j][k]<Max&&dist[i][j]+map[k][i]+map[j][k]<min)//注意这里的k ，i，j的顺序是满足有向图的	
						{
							min=dist[i][j]+map[k][i]+map[j][k];	
							solve(i,j,k);//记录最小环 
						}			
					}	
			}	
			for(i=1;i<=n;i++)	for(j=1;j<=n;j++)
					if(dist[i][j]>dist[i][k]+dist[k][j])
					{	dist[i][j]=dist[i][k]+dist[k][j];		r[i][j]=r[k][j];		}
		}
		if(min==Max)		printf("No solution.\n");
		else
		{
			for(i=0;i<outnum-1;i++)			printf("%d ",out[i]);
			printf("%d",out[outnum-1]);		printf("\n");	
		}	
	}
}
