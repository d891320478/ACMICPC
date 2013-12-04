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
priority_queue<double> q;
int n;
double a,b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		q.push(a);
	}
	while (n>1)
	{
		a=q.top(); q.pop();
		b=q.top(); q.pop();
		q.push(2*sqrt(a*b));
		n--;
	}
	printf("%.3f\n",q.top());
	return 0;
}