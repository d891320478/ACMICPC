#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 110
#define M 10010
int n,a[N][N],d[N],i,j,k,vis[N];
char s[20];
int main ()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	for(j=0;j<i;j++)
	{
		scanf("%s",s);
		if(strcmp(s,"x")==0) a[i][j]=a[j][i]=INF;
		else a[i][j]=a[j][i]=atoi(s);
	}
	for(i=0;i<n;i++) d[i]=a[0][i];
	vis[0]=1;
	for(i=1;i<n;i++)
	{
		int min=INF;
		for(j=0;j<n;j++)
			if(! vis[j])
			if(d[j]<min)
			{
				min=d[j];
				k=j;
			}
		vis[k]=1;
		for(j=0;j<n;j++)
			if(! vis[j])
			if(d[j]>d[k]+a[k][j])
				d[j]=d[k]+a[k][j];
	}
	printf("%d\n",d[max_element(d,d+n)-d]);
	
	return 0;
}