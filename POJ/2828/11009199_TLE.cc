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
#define N 2000010
#define M 10010
int n;
int a[N],b[N],ans[N];
int tree[N<<2];
void build(int l,int r,int rt)
{
	tree[rt]=r-l+1;
	if(l==r) return;
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
}
int query(int pos,int l,int r,int rt)
{
	tree[rt]--;
	if(l==r) return l;
	int m=(l+r)>>1;
	if(tree[rt<<1]>=pos) return query(pos,l,m,rt<<1);
	else return query(pos-tree[rt<<1],m+1,r,rt<<1|1);
}
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			a[i]++;
		}
		for(int i=n;i>=1;i--)
			ans[query(a[i],1,n,1)]=b[i];
		for(int i=1;i<=n;i++)
		{
			if(i>1) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}