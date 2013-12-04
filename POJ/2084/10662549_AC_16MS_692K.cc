#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
int n,a[110];
void mult(int *a,int b)
{
	for(int i=1;i<=a[0];i++)
	{
		a[i]*=b;
		if(i-1>0)
		{
			a[i]+=a[i-1]/10;
			a[i-1]%=10;
		}
	}
	while (a[a[0]]>9)
	{
		a[a[0]+1]=a[a[0]]/10;
		a[a[0]++]%=10;
	}
}
void divide(int *a,int b)
{
	int tmp=0;
	for(int i=a[0];i>0;i--)
	{
		tmp=tmp*10+a[i];
		a[i]=tmp/b;
		tmp%=b;
	}
	while (a[a[0]]==0 && a[0]>1) a[0]--;
}
int main ()
{
	while (scanf("%d",&n) && n>0)
	{
		SET(a,0);
		a[0]=a[1]=1;
		for(int i=1;i<=n;i++)
		{
			mult(a,i+n);
			divide(a,i);
		}
		divide(a,n+1);
		for (int i=a[0];i>0;i--)
			printf("%d",a[i]);
		printf("\n");
	}
	
	return 0;
}