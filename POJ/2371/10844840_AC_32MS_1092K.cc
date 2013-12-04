#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
#define INF 1<<30
#define EPS 1e-8
#define N 100010
#define M 10000
int n,a[N],m,k,i;
string s;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	//cin>>s;
	scanf("\n###\n%d",&m);
	while (m--)
	{
		scanf("%d",&k);
		printf("%d\n",a[k]);
	}
	
	return 0;
}