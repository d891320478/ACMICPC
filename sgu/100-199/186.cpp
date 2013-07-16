#include <cstdio>
#include <algorithm>
using namespace std;
#define N 110
int n,ans,a[N];
int main ()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	sort(a,a+n);
	ans=0;
	int l=0,r=n-1;
	while (l<r)
	{
		++ans;
		--a[l];
		--r;
		if(a[l]==0) ++l;
	}
	printf("%d\n",ans);
	return 0;
}
