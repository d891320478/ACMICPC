#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
int main()
{
	int n,a[N];
	while (scanf("%d",&n)!=-1)
	{
		a[0]=0;
		for(int i=2;n>=i;i++)
			a[++a[0]]=i,n-=i;
		if(n==a[a[0]])
		{
			for(int i=2;i<=a[0];i++)
				printf("%d ",a[i]);
			printf("%d\n",a[a[0]]+2);
		}
		else
		{
			for(int i=a[0];n;i--,n--)
				a[i]++;
			for(int i=1;i<a[0];i++)
				printf("%d ",a[i]);
			printf("%d\n",a[a[0]]);
		}
	}
	return 0;
}