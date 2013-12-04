#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 110
const int dx[]={1,0,-1,0};
const int dy[]={0,-1,0,1};
int n,m,s,q;
int a[N][3];
int vis[M][M];
int fx(char ch)
{
	if(ch=='E') return 3;
	if(ch=='N') return 0;
	if(ch=='W') return 1;
	if(ch=='S') return 2;
}
int main()
{
	int tt,flag;
	scanf("%d",&tt);
	while (tt--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&m,&n);
		scanf("%d%d",&s,&q);
		for(int i=1;i<=s;i++)
		{
			int x,y; char ch;
			scanf("%d %d %c",&x,&y,&ch);
			a[i][1]=x;
			a[i][0]=y;
			a[i][2]=fx(ch);
			vis[y][x]=i;
		}
		flag=1;
		while (q)
		{
			q--;
			int id,x;
			char ch;
			scanf("%d %c %d",&id,&ch,&x);
			if(! flag) continue;
			if(ch=='L')
			{
				x%=4;
				a[id][2]=(a[id][2]+x%4+4)%4;
			}
			else if(ch=='R')
			{
				x%=4;
				a[id][2]=(a[id][2]-x%4+4)%4;
			}
			else if(ch=='F')
			{
				vis[a[id][0]][a[id][1]]=0;
				while (x--)
				{
					a[id][0]+=dx[a[id][2]];
					a[id][1]+=dy[a[id][2]];
					/*
					if(id==2)
					{
						printf("x = %d y = %d\n",a[id][0],a[id][1]);
					}
					*/
					if(vis[a[id][0]][a[id][1]])
					{
						printf("Robot %d crashes into robot %d\n",id,vis[a[id][0]][a[id][1]]);
						flag=0;
						break;
					}
					if(a[id][0]<=0 || a[id][0]>n || a[id][1]<=0 || a[id][1]>m)
					{
						printf("Robot %d crashes into the wall\n",id);
						flag=0;
						break;
					}
				}
				if(! flag) continue;
				vis[a[id][0]][a[id][1]]=id;
			}
			/*
			for(int i=1;i<=s;i++)
				printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
			printf("\n");
			*/
		}
		if(flag) printf("OK\n");
	}
	return 0;
}