#include <cstdio>
#include <algorithm>
using namespace std;
int f[1000002]={0,0,0};
int a[1000002],i,j,n;
int main()
{
	for(i=5;i<1000002;i+=4)
		if(! f[i])
		{
			for(j=5;i*j<1000002;j+=4)
			{
				if(f[i]==0 && f[j]==0)f[i*j]=1;
				else f[i*j]=2;
			}
		}
	int sum=0;
	for(i=0;i<1000002;i++)
	{
		if(f[i]==1)sum++;
		a[i]=sum;
	}
	while (scanf("%d",&n) && n)
		printf("%d %d\n",n,a[n]);
	
	return 0;
}