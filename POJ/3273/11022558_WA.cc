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
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1000010
#define M 10010
int l,r,mid;
int n,m,a[N];
int main ()
{
	while(scanf("%d%d",&n,&m)!=-1)
	{
		l=r=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			r+=a[i];
			l=max(l,a[i]);
		}
		while (l<r)
		{
			mid=(l+r)>>1;
			int sum=0,ans=a[1];
			for(int i=2;i<=n;i++)
			{
				if(ans+a[i]>mid)
				{
					ans=a[i];
					sum++;
				}else ans+=a[i];
			}
			if(sum>m) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}