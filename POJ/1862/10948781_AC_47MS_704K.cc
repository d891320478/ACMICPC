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
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
int n,i;
double a[N];
int main ()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf",&a[i]);
	sort(a,a+n);
	for(i=n-2;i>=0;i--) a[i]=sqrt(a[i]*a[i+1])*2;
	printf("%.3f\n",a[0]);
	
	return 0;
}