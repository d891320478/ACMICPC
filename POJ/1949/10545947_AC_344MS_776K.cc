#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 10010
#define M 1000010
int d[N],a[N];
int i,j,k,ans;
int n;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&j);
		while (j--)
		{
			scanf("%d",&k);
			d[i]=max(d[i],d[k]);
		}
		d[i]+=a[i];
		ans=max(d[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}