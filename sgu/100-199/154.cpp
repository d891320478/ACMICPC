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
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 100010
long long l=1,r=INF,mid,n;
long long check(int a)
{
	long long ans=0,p=5;
	while (a/p)
	{
		ans+=a/p;
		p*=5;
	}
	return ans;
}
int main ()
{
	cin>>n;
	while (l<r)
	{
		mid=l+r>>1;
		if(check(mid)<n) l=mid+1;
		else r=mid;
	}
	if(check(l)==n) cout<<l<<endl;
	else cout<<"No solution"<<endl;
	return 0;
}
