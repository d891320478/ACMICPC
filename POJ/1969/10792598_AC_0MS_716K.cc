#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 500010
#define M 10010
int n,a[N],m,la,k;
int search(int x,int l,int r)
{
	int mid;
	while (l<r)
	{
		mid=(l+r+1)>>1;
		if(a[mid]>=x) r=mid-1;
		else l=mid;
	}
	return l;
}
int main ()
{
	int i;
	a[0]=0;
	a[1]=1;
	for(i=2;a[i-1]<=10000000;i++)
		a[i]=a[i-1]+i;
	la=i-1;
	while (scanf("%d",&n)!=-1)
	{
		k=n;
		m=search(n,0,la);
		n-=a[m];
		printf("TERM %d IS ",k);
		if(m%2==0)printf("%d/%d\n",m+2-n,n);
		else printf("%d/%d\n",n,m+2-n);
	}
	return 0;
}