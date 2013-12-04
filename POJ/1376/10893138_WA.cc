#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 110
#define M 10010
int n,m;
int a[N][N],b,x00,y00,vis[N][N][5];
int q[5*N*N][4],l[N*N*5],head,tail;
char ch[8];
void BFS()
{
	head=0,tail=0;
	while (head<=tail)
	{
		if(! vis[q[head][0]][q[head][1]][(q[head][2]+1)%4])
		{
			tail++;l[tail]=l[head]+1;
			 
			q[tail][0]=q[head][0];
			q[tail][1]=q[head][1];
			q[tail][2]=(q[head][2]+1)%4;
			vis[q[head][0]][q[head][1]][(q[head][2]+1)%4]=1;
		}
		if(! vis[q[head][0]][q[head][1]][(q[head][2]+3)%4])
		{
			tail++;l[tail]=l[head]+1;
			 
			q[tail][0]=q[head][0];
			q[tail][1]=q[head][1];
			q[tail][2]=(q[head][2]+3)%4;
			vis[q[head][0]][q[head][1]][(q[head][2]+3)%4]=1;
		}
		if(q[head][2]==0)
		{
			if(q[head][1]-1>=0)
			if(a[q[head][0]][q[head][1]-1])
			{
				if(! vis[q[head][0]][q[head][1]-1][q[head][2]])
				{
					tail++;l[tail]=l[head]+1;
					 
					q[tail][0]=q[head][0];
					q[tail][1]=q[head][1]-1;
					q[tail][2]=q[head][2];
					vis[q[head][0]][q[head][1]-1][q[head][2]]=1;
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
				}
				if(q[head][1]-2>=0)
				if(a[q[head][0]][q[head][1]-2])
				{
					if(! vis[q[head][0]][q[head][1]-2][q[head][2]])
					{
						tail++;l[tail]=l[head]+1;
						 
						q[tail][0]=q[head][0];
						q[tail][1]=q[head][1]-2;
						q[tail][2]=q[head][2];
						vis[q[head][0]][q[head][1]-2][q[head][2]]=1;
					}
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
					if(q[head][1]-3>=0)
					if(a[q[head][0]][q[head][1]-3])
					{
						if(! vis[q[head][0]][q[head][1]-3][q[head][2]])
						{
							tail++;l[tail]=l[head]+1;
							 
							q[tail][0]=q[head][0];
							q[tail][1]=q[head][1]-3;
							q[tail][2]=q[head][2];
							vis[q[head][0]][q[head][1]-3][q[head][2]]=1;
						}
						if(q[tail][0]==x00 && q[tail][1]==y00)
						{
							printf("%d\n",l[tail]);
							return;
						}
					}
				}
			}
		}

		if(q[head][2]==2)
		{
			if(q[head][1]+1<=n)
			if(a[q[head][0]][q[head][1]+1])
			{
				if(! vis[q[head][0]][q[head][1]+1][q[head][2]])
				{
					tail++;l[tail]=l[head]+1;
					 
					q[tail][0]=q[head][0];
					q[tail][1]=q[head][1]+1;
					q[tail][2]=q[head][2];
					vis[q[head][0]][q[head][1]+1][q[head][2]]=1;
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
				}
				if(q[head][1]+2<=n)
				if(a[q[head][0]][q[head][1]+2])
				{
					if(! vis[q[head][0]][q[head][1]+2][q[head][2]])
					{
						tail++;l[tail]=l[head]+1;
						q[tail][0]=q[head][0];
						q[tail][1]=q[head][1]+2;
						q[tail][2]=q[head][2];
						vis[q[head][0]][q[head][1]+2][q[head][2]]=1;
					}
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
					if(q[head][1]+3<=n)
					if(a[q[head][0]][q[head][1]+3])
					{
						if(! vis[q[head][0]][q[head][1]+3][q[head][2]])
						{
							tail++;l[tail]=l[head]+1;
							q[tail][0]=q[head][0];
							q[tail][1]=q[head][1]+3;
							q[tail][2]=q[head][2];
							vis[q[head][0]][q[head][1]+3][q[head][2]]=1;
						}
						if(q[tail][0]==x00 && q[tail][1]==y00)
						{
							printf("%d\n",l[tail]);
							return;
						}
					}
				}
			}
		}

		if(q[head][2]==1)
		{
			if(q[head][0]+1<=m)
			if(a[q[head][0]+1][q[head][1]])
			{
				if(! vis[q[head][0]+1][q[head][1]][q[head][2]])
				{
					tail++;l[tail]=l[head]+1;
					 
					q[tail][0]=q[head][0]+1;
					q[tail][1]=q[head][1];
					q[tail][2]=q[head][2];
					vis[q[head][0]+1][q[head][1]][q[head][2]]=1;
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
				}
				if(q[head][0]+2<=m)
				if(a[q[head][0]+2][q[head][1]])
				{
					if(! vis[q[head][0]+2][q[head][1]][q[head][2]])
					{
						tail++;l[tail]=l[head]+1;
						q[tail][0]=q[head][0]+2;
						q[tail][1]=q[head][1];
						q[tail][2]=q[head][2];
						vis[q[head][0]+2][q[head][1]][q[head][2]]=1;
					}
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
					if(q[head][0]+3<=n)
					if(a[q[head][0]+3][q[head][1]])
					{
						if(! vis[q[head][0]+3][q[head][1]][q[head][2]])
						{
							tail++;l[tail]=l[head]+1;
							q[tail][0]=q[head][0]+3;
							q[tail][1]=q[head][1];
							q[tail][2]=q[head][2];
							vis[q[head][0]+3][q[head][1]][q[head][2]]=1;
						}
						if(q[tail][0]==x00 && q[tail][1]==y00)
						{
							printf("%d\n",l[tail]);
							return;
						}
					}
				}
			}
		}


		if(q[head][2]==3)
		{
			if(q[head][0]-1>=0)
			if(a[q[head][0]-1][q[head][1]])
			{
				if(! vis[q[head][0]-1][q[head][1]][q[head][2]])
				{
					tail++;l[tail]=l[head]+1;
					l[tail]=l[head]-1;
					q[tail][0]=q[head][0]-1;
					q[tail][1]=q[head][1];
					q[tail][2]=q[head][2];
					vis[q[head][0]-1][q[head][1]][q[head][2]]=1;
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
				}
				if(q[head][0]-2>=0)
				if(a[q[head][0]-2][q[head][1]])
				{
					if(! vis[q[head][0]-2][q[head][1]][q[head][2]])
					{
						tail++;l[tail]=l[head]+1;
						q[tail][0]=q[head][0]-2;
						q[tail][1]=q[head][1];
						q[tail][2]=q[head][2];
						vis[q[head][0]-2][q[head][1]][q[head][2]]=1;
					}
					if(q[tail][0]==x00 && q[tail][1]==y00)
					{
						printf("%d\n",l[tail]);
						return;
					}
					if(q[head][0]-3<=n)
					if(a[q[head][0]-3][q[head][1]])
					{
						if(! vis[q[head][0]-3][q[head][1]][q[head][2]])
						{
							tail++;l[tail]=l[head]+1;
							q[tail][0]=q[head][0]-3;
							q[tail][1]=q[head][1];
							q[tail][2]=q[head][2];
							vis[q[head][0]-3][q[head][1]][q[head][2]]=1;
						}
						if(q[tail][0]==x00 && q[tail][1]==y00)
						{
							printf("%d\n",l[tail]);
							return;
						}
					}
				}
			}
		}
		head++;
	}
	printf("-1\n");
}
int main ()
{
	int i,j;
	while (scanf("%d %d",&n,&m) && n+m)
	{
		memset(a,-1,sizeof(a));
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&b);
			if(b==1) a[i][j]=a[i-1][j-1]=a[i-1][j]=a[i][j-1]=0;
			else
			{
				if(a[i][j]==-1) a[i][j]=1;
				if(a[i-1][j]==-1) a[i-1][j]=1;
				if(a[i][j-1]==-1) a[i][j-1]=1;
				if(a[i-1][j-1]==-1) a[i-1][j-1]=1;
			}
		}
		scanf("%d %d ",&q[0][0],&q[0][1]);
		scanf("%d %d ",&x00,&y00);
		scanf("%s",ch);
		if(q[0][0]==x00 && q[0][1]==y00)
		{
			printf("0\n");
			continue;
		}
		if(a[q[0][0]][q[0][1]]==0)
		{
			printf("-1\n");
			continue;
		}
		if(strcmp(ch,"north")==0) q[0][2]=3;
		if(strcmp(ch,"south")==0) q[0][2]=1;
		if(strcmp(ch,"west")==0) q[0][2]=0;
		if(strcmp(ch,"east")==0) q[0][2]=2;
		memset(vis,0,sizeof(vis));
		vis[q[0][0]][q[0][1]][q[0][2]]=1;
		l[0]=0;
		swap(n,m);
		BFS();
	}
	
	return 0;
}