#include <cstdio>
#include <iostream>
using namespace std;
#define N 500010
int n;
long long a[N];
long long ans;
void builddown(int father)
{
	int son=father<<1;
	while (son<=n)
	{
		if(son+1<=n && a[son+1]<a[son]) ++son;
		if(a[father]>a[son]) swap(a[father],a[son]);
		else return;
		father=son;
		son<<=1;
	}
}
void buildup(int son)
{
	int father=son>>1;
	while (father>=1)
	{
		if(a[father]>a[son]) swap(a[father],a[son]);
		else return;
		son=father;
		father>>=1;
	}
}
int main ()
{
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=n/2;i>=1;--i) builddown(i);
		ans=0;
		while (n>1)
		{
			long long b=a[1];
			a[1]=a[n--];
			builddown(1);
			ans+=b+a[1];
			a[1]+=b;
			builddown(1);
		}
		printf("%lld\n",ans);
	return 0;
}
