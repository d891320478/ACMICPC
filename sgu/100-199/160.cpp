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
#define N 1010
#define M 10010
int a[M],pre[N],ans[N],id[N],zzz[N],ans2[N];
int n,m;
void print(int now)
{
	if(now==1) return;
	print(pre[now]);
	zzz[++zzz[0]]=id[now];
}
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(ans,0,sizeof(ans));
		memset(id,0,sizeof(id));
		ans[1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				ans2[j]=ans[j];
			for(int j=1;j<=m;j++)
			if(ans[j])
			if(! ans[a[i]*j%m])
			{
				int k=a[i]*j%m;
				ans2[k]=1;
				pre[k]=j;
				id[k]=i;
			}
			for(int j=1;j<=m;j++)
				ans[j]=ans2[j];
		}
		//for(int i=1;i<=m;i++)
		//	printf("%d %d %d\n",ans[i],pre[i],id[i]);
		zzz[0]=0;
		for(int i=m-1;i>=0;i--)
		if(ans[i])
		{
			printf("%d\n",i);
			print(i);
			break;
		}
		for(int i=1;i<=zzz[0];i++)
		{
			printf("%d",zzz[i]);
			if(i<zzz[0]) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
