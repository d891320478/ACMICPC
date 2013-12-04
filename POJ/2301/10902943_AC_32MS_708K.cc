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
int a,b;
int main ()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&a,&b);
		if(((a+b) & 1) || b>a) printf("impossible\n");
		else printf("%d %d\n",(a+b)/2,(a-b)/2);
	}
	
	return 0;
}