#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[10010];
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n+1);
	printf("%d\n",a[n/2+n%2]);
	return 0;
}