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
#define N 1000010
#define M 10010
int n,ans=-1,a[N],sums;
int q[N],head,tail;
map<int,int> ha,vis;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ha[a[i]]=1;
	}
	sums=ha.size();
	head=1;tail=0;
	for(int i=1;i<=n;i++)
	{
		if(! vis[a[i]]) sums--;
		vis[a[i]]+=1;
		q[++tail]=a[i];
		while(vis[q[head]]>1 && head<=tail)
		{
			vis[q[head]]-=1;
			head++;
		}
		if(sums==0)
		if(ans==-1 || ans>tail-head+1) ans=tail-head+1;
		//printf("head = %d tail = %d ans = %d\n",head,tail,ans);
	}
	printf("%d\n",ans);
	
	return 0;
}