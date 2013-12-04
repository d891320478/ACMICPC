#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[10010],p,q,x,y,i;
int main ()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while (m--) next_permutation(a+1,a+1+n);
		for(i=1;i<n;i++) printf("%d ",a[i]);	printf("%d\n",a[n]);
	}
	return 0;
}