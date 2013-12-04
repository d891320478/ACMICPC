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
#define M 80
char s[N][M],a[M];
int c,f[M],next[N];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	memset(f,0,sizeof(f));
	f[m]=n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		strcpy(a,s[i]);
		for(int j=m-1;j>0;j--)
		{
			a[j]=0;
			int flag=1;
			for(int x=0,y=0;s[i][y];x++,y++)
			{
				if(! a[x]) x=0;
				if(a[x]!=s[i][y]){flag=0;break;}
			}
			if(flag) f[j]++;
		}
	}
	int ans=m;
	for(int i=0;i<=m;i++)
		if(f[i]==n)
		{
			for(int j=0;j<n;j++)
				s[j][i]=0;
			ans=i;
			break;
		}
	int j=-1;
	next[0]=-1;
	for(int i=1;i<n;i++)
	{
		while(j>-1 && strcmp(s[j+1],s[i])) j=next[j];
		if(strcmp(s[j+1],s[i])==0) j++;
		next[i]=j;
	}
	printf("%d\n",ans*(n-1-next[n-1]));
	return 0;
}