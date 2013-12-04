#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define lowbit(x) ((x)&(-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define N 500010
int ss[10]={2,3,5,7,11,13,17,19,23,29};
int n,k;
int tree[N];
int a[N];
char b[N][20];
int ans,sum;
int pre[N],nxt[N];
int getsum(int x)
{
	int ans=0;
	while (x)
	{
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int query(int l,int r)
{
	return getsum(r)-getsum(l-1);
}
void update(int x,int d)
{
	while (x<=n)
	{
		tree[x]+=d;
		x+=lowbit(x);
	}
}
void dfs(int _i,int now,int _ss,int limit)
{
	if(_i>9) return;
	if(now>n) return;
	if(_ss>sum || _ss==sum && ans>now)
	{
		ans=now;
		sum=_ss;
	}
	int p=ss[_i];
	for(int i=1;i<=limit;++i,p*=ss[_i])
	{
		if(now*p>n) break;
		dfs(_i+1,now*p,_ss*(i+1),i);
	}
}
int main()
{
	while (scanf("%d%d",&n,&k)!=-1)
	{
		for(int i=1;i<=n;++i) scanf("%s %d",b[i],&a[i]);
		for(int i=1;i<=n;++i)
		{
			pre[i]=i-1;
			nxt[i]=i+1;
			update(i,1);
		}
		pre[1]=n;
		nxt[n]=1;
		int _n=n,out;
		ans=sum=1;
		dfs(0,1,1,20);
		for(int i=1;i<=ans;++i)
		{
			update(k,-1);
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
				int sums=query(1,k);
				if(sums>=_x)
				{
					l=1,r=k;
					while (l<r)
					{
						mid=l+r+1>>1;
						if(query(mid,k)<_x) r=mid-1;
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
						if(query(mid,n)<_x) r=mid-1;
						else l=mid;
					}
				}
			}
			else
			{
				int sums=query(k,n);
				if(sums>=_x)
				{
					l=k,r=n;
					while (l<r)
					{
						mid=l+r>>1;
						if(query(k,mid)<_x) l=mid+1;
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
						if(query(1,mid)<_x) l=mid+1;
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