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
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1000010
#define M 10010
deque<int> q1,q2;
int n,k,a[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<k;i++)
	{
		while (! q1.empty() && a[q1.back()]<a[i]) q1.pop_back();
		q1.push_back(i);
		while (! q2.empty() && a[q2.back()]>a[i]) q2.pop_back();
		q2.push_back(i);
	}
	for(int i=k;i<=n;i++)
	{
		while (! q2.empty() && a[q2.back()]>a[i]) q2.pop_back();
		q2.push_back(i);
		while (i-q2.front()+1>k) q2.pop_front();
		printf("%d",a[q2.front()]);
		if(i<n) printf(" ");
		else printf("\n");
	}
	for(int i=k;i<=n;i++)
	{
		while (! q1.empty() && a[q1.back()]<a[i]) q1.pop_back();
		q1.push_back(i);
		while (i-q1.front()+1>k) q1.pop_front();
		printf("%d",a[q1.front()]);
		if(i<n) printf(" ");
		else printf("\n");
	}
	return 0;
}