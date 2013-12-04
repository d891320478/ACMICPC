#include <cstdio>
int n,a[50010],m1,m2,sum;
int main ()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		sum=0;
		m1=m2=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if(sum>m1)m1=sum;
			else if(sum>m2)m2=sum;
			if(sum<0)sum=0;
		}
		printf("%d\n",m1+m2);
	}
	
	return 0;
}