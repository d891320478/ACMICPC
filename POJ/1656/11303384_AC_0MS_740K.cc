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
#define N 110
#define M 10010
int a[N][N];
int m;
char s[20];
int x,y,r;
int main()
{
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s %d %d %d",s,&x,&y,&r);
		if(s[0]=='B')
		{
			for(int i=x;i<=x+r-1;i++)
			for(int j=y;j<=y+r-1;j++)
				a[i][j]=1;
		}
		if(s[0]=='W')
		{
			for(int i=x;i<=x+r-1;i++)
			for(int j=y;j<=y+r-1;j++)
				a[i][j]=0;
		}
		if(s[0]=='T')
		{
			int ans=0;
			for(int i=x;i<=x+r-1;i++)
			for(int j=y;j<=y+r-1;j++)
				ans+=a[i][j];
			printf("%d\n",ans);
		}
	}
	return 0;
}