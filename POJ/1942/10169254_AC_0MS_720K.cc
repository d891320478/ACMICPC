#include <cstdio>
#include <iostream>
using namespace std;
double m,n,i,sum,ans;

int main()
{
	while (scanf("%lf%lf",&m,&n)!=EOF)
	{
		if(m==0 && n==0)break;
		if(m<n)swap(m,n);
		ans=1;
		for(i=1;i<=n;i++)
			ans=ans*(m+i)/i;
		printf("%.0f\n",ans);
	}
	
	return 0;
}
