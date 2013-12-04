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
#define N 310
#define M 10010
typedef pair<int,int> PAIR;
PAIR heap[N*N];
int n,m,lh;
int a[N][N],vis[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void build_up(int son)
{
	int father=son/2;
	while (father>=1)
	{
		if(a[heap[father].first][heap[father].second]>a[heap[son].first][heap[son].second]) swap(heap[father],heap[son]);
		else return;
		son=father;
		father/=2;
	}
}
void build_down(int father)
{
	int son=father*2;
	while (son<=lh)
	{
		if(son+1<=lh)
		if(a[heap[son+1].first][heap[son+1].second]<a[heap[son].first][heap[son].second]) son++;
		if(a[heap[father].first][heap[father].second]>a[heap[son].first][heap[son].second]) swap(heap[father],heap[son]);
		else return;
		father=son;
		son*=2;
	}
}
int main()
{
	while (scanf("%d%d",&m,&n)!=-1)
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			if(i==1 || i==n ||j==1 ||j==m)
			{
				vis[i][j]=1;
				heap[++lh]=make_pair(i,j);
				build_up(lh);
			}
		}
		int mn=INF;
		long long ans=0;
		while (lh)
		{
			int x=heap[1].first,y=heap[1].second;
			heap[1]=heap[lh--];
			build_down(1);
			int flag=0;
			for(int i=0;i<4;i++)
				if(x+dx[i]>1 && x+dx[i]<n)
				if(y+dy[i]>1 && y+dy[i]<m)
				if(! vis[x+dx[i]][y+dy[i]])
				if(a[x][y]<a[x+dx[i]][y+dy[i]])
				{
					vis[x+dx[i]][y+dy[i]]=1;
					heap[++lh]=make_pair(x+dx[i],y+dy[i]);
					build_up(lh);
				}
				else
				{
					ans+=a[x][y]-a[x+dx[i]][y+dy[i]];
					a[x+dx[i]][y+dy[i]]=a[x][y];
					vis[x+dx[i]][y+dy[i]]=1;
					heap[++lh]=make_pair(x+dx[i],y+dy[i]);
					build_up(lh);
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}