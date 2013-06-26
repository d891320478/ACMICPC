#include <cstdio>
#include <iostream>
using namespace std;
int a=1,b=1,sum=2;
int main ()
{
	int k;
	scanf("%d",&k);
	if(k==1) printf("1\n");
	else if(k==2) printf("2\n");
	else
	{
		k-=2;
		while (k--)
		{
			a=a+b;
			sum+=a;
			swap(a,b);
		}
		printf("%d\n",sum);
	}
	return 0;
}
