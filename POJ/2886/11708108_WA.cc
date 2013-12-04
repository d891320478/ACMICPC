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
#include<utility>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 500010
int ss[10]={2,3,5,7,11,13,17,19,23,29};
int cs[10];
int n,k;
int tree[N<<1];
int a[N];
char b[N][12];
int ans,sum;
int pre[N],nxt[N];
void build(int l,int r)
{
	int rt=IDX(l,r);
	tree[rt]=r-l+1;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid);
	build(mid+1,r);
}
int query(int L,int R,int l,int r)
{
	int rt=IDX(l,r);
	if(L<=l && R>=r) return tree[rt];
	int mid=l+r>>1,aaa=0;
	if(L<=mid) aaa+=query(L,R,l,mid);
	if(R>mid) aaa+=query(L,R,mid+1,r);
	return aaa;
}
void update(int l,int r,int x)
{
	int rt=IDX(l,r);
	--tree[rt];
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) update(l,mid,x);
	else update(mid+1,r,x);
}
void dfs(int _i,int now)
{
	if(_i>9) return;
	if(now>n) return;
	int _ss=1;
	for(int i=0;i<=_i;i++) _ss*=cs[i]+1;
	if(_ss>sum || _ss==sum && ans>now)
	{
		ans=now;
		sum=_ss;
	}
	for(int i=1;i<=(_i==0?20:cs[_i-1]);++i)
	{
		cs[_i]=i;
		now*=ss[_i];
		dfs(_i+1,now);
		cs[_i]=0;
	}
}
int main()
{
	while (scanf("%d%d",&n,&k)!=-1)
	{
		memset(cs,0,sizeof(cs));
		for(int i=1;i<=n;++i) scanf("%s%d",b[i],&a[i]);
		for(int i=1;i<=n;++i)
		{
			pre[i]=i-1;
			nxt[i]=i+1;
		}
		pre[1]=n;
		nxt[n]=1;
		build(1,n);
		int _n=n,out;
		ans=sum=1;
		dfs(0,1);
		for(int i=1;i<=ans;++i)
		{
			update(1,n,k);
			nxt[pre[k]]=nxt[k];
			pre[nxt[k]]=pre[k];
			out=k;
			--_n;
			if(_n==0) break;
			int _x=ABS(a[k]),l,r,mid;
			_x=_x%_n;
			if(_x==0) _x=_n;
			if(a[k]<0)
			{
				int sums=query(1,k,1,n);
				if(sums>=_x)
				{
					l=1,r=k;
					while (l<r)
					{
						mid=l+r+1>>1;
						if(query(mid,k,1,n)<_x) r=mid-1;
						else l=mid;
					}
				}
				else
				{
					_x-=sums;
					l=k+1,r=n;
					while (l<r)
					{
						mid=l+r+1>>1;
						if(query(mid,n,1,n)<_x) r=mid-1;
						else l=mid;
					}
				}
			}
			else
			{
				int sums=query(k,n,1,n);
				if(sums>=_x)
				{
					l=k,r=n;
					while (l<r)
					{
						mid=l+r>>1;
						if(query(k,mid,1,n)<_x) l=mid+1;
						else r=mid;
					}
				}
				else
				{
					_x-=sums;
					l=1,r=k-1;
					while (l<r)
					{
						mid=l+r>>1;
						if(query(1,mid,1,n)<_x) l=mid+1;
						else r=mid;
					}
				}
			}
			k=l;
		}
		printf("%s %d\n",b[out],sum);
	}
	return 0;
}