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
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 60
#define MM 1010
int n,m,t,x,y;
char s[MM][MM],a[NN][NN];
long long hash[MM][MM],ha[MM];
int main()
{
	int tt=0;
	while (scanf("%d %d %d %d %d",&n,&m,&t,&x,&y) && n+m+t+x+y)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			hash[i][0]=0;
			for(int j=0;j<y;j++)
				if(s[i][j]=='*') hash[i][0]+=1LL<<j;
			for(int j=y;j<m;j++)
			{
				hash[i][j-y+1]=(hash[i][j-y]>>1);
				if(s[i][j]=='*') hash[i][j-y+1]+=(1LL<<(y-1));
			}
		}
		int sum=0;
		while (t--)
		{
			for(int i=0;i<x;i++)
			{
				scanf("%s",a[i]);
				ha[i]=0;
				for(int j=0;j<y;j++)
					if(a[i][j]=='*') ha[i]+=1LL<<j;
			}
			int flag=0;
			for(int i=0;i+x-1<n && ! flag;i++)
			{
				for(int j=0;j+y-1<m && ! flag;j++)
				if(hash[i][j]==ha[0])
				{
					flag=1;
					for(int k=1;k<x;k++)
						if(hash[i+k][j]!=ha[k])
						{
							flag=0;
							break;
						}
				}
			}
			sum+=flag;
		}
		printf("Case %d: %d\n",++tt,sum);
	}
	return 0;
}