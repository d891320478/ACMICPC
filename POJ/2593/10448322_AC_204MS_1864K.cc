#include <cstdio>
#include <iostream>
using namespace std;
int n,a[100010],sum,l[100010],r[100010],k;
int main ()
{
	int t;
	while (scanf("%d",&n) && n)
	{
		sum=0;
		l[0]=r[n+1]=-1600000000;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			l[i]=max(sum,l[i-1]);
			if(sum<0)sum=0;
		}
		sum=0;
		for(int i=n;i>=1;i--)
		{
			sum+=a[i];
			r[i]=max(r[i+1],sum);
			if(sum<0)sum=0;
		}
		k=-1600000000;
		for(int i=1;i<n;i++)
			k=max(k,r[i+1]+l[i]);
		printf("%d\n",k);
	}
	
	return 0;
}