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
#define N 10010
#define M 10010
double a,b,c,d,e;
int main ()
{
	while (scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e)!=-1)
	{
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		if(d>e) swap(d,e);
		if(a<=d && b<=e) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}