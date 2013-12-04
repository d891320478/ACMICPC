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
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
int n;
char s[20];
int a[20],b[20];
int w[1<<17];
int main()
{
	w[0]=0;
	for(int i=1;i<=(1<<16);i++) w[i]=w[i>>1]+(i&1);
	int tt=fastget();
	while (tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			a[i]=0;
			for(int j=0;j<n;j++)
				if(s[j]=='w') a[i]|=1<<j;
		}
		int sum,ans=INF;
		for(int i=0;i<(1<<n);i++)
		//if(i==(1<<n)-1)
		{
			sum=w[i];
			for(int j=1;j<=n;j++) b[j]=a[j];
			b[1]=b[1]^i^((i<<1)&((1<<n)-1))^(i>>1);
			b[2]^=i;
			//printf("b[1] = %d\n",b[1]);
			//printf("b[2] = %d\n",b[2]);
			for(int j=2;j<=n;j++)
			{
				sum+=w[b[j-1]];
				b[j]=b[j]^(b[j-1])^(b[j-1]>>1)^((b[j-1]<<1)&((1<<n)-1));
				b[j+1]^=b[j-1];
				//printf("b[%d] = %d\nb[%d] = %d\n",j,b[j],j+1,b[j+1]);
			}
			if(b[n]==0) ans=min(ans,sum);
		}
		if(ans<INF) printf("%d\n",ans);
		else printf("inf\n");
	}
	return 0;
}