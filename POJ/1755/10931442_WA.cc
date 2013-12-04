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
#define N 110
#define M 10010
int n;
int a[N],b[N],c[N];
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int i=1;i<=n;i++)
		{
			int j;
			for(j=1;j<=n;j++)
				if(j!=i)
					if(a[i]<=a[j] && b[i]<=b[j] && c[i]<=c[j]) break;
			if(j>n) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}