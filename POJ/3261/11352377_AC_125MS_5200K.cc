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
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 1000010
#define M 20
int wx[N],wy[N],wss[N],wv[N];
bool cmp(int *r,int n,int a,int b,int l){ return a+l<n && b+l<n && r[a]==r[b] && r[a+l]==r[b+l]; }
void da(int s[],int sa[],int rank[],int height[],int n,int m)
{
	int *x=wx,*y=wy,p; int i,j,k;
	for(i=0;i<m;i++) wss[i]=0;
	for(i=0;i<n;i++) wss[x[i]=s[i]]++;
	for(i=1;i<m;i++) wss[i]+=wss[i-1];
	for(i=n-1;i>=0;i--) sa[--wss[x[i]]]=i;
	for(j=1,p=1;p<n && j<n;j*=2,m=p)
	{
		for(i=n-j,p=0;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]-j>=0) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) wv[i]=x[y[i]];
		for(i=0;i<m;i++) wss[i]=0;
		for(i=0;i<n;i++) wss[wv[i]]++;
		for(i=1;i<m;i++) wss[i]+=wss[i-1];
		for(i=n-1;i>=0;i--) sa[--wss[wv[i]]]=y[i];
		for(swap(x,y),p=1,i=1,x[sa[0]]=0;i<n;i++)
			x[sa[i]]=cmp(y,n,sa[i-1],sa[i],j)?p-1:p++;
	}
	for(i=0;i<n;i++) rank[sa[i]]=i;
	for(i=j=k=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
		for(k?k--:0,j=sa[rank[i]-1];i+k<n && j+k<n && s[i+k]==s[j+k];k++);
	height[0]=0;
}
int str[N],sa[N],rank[N],height[N];
int mx[M][N],idx[N],p[M];
void makermq(int val[],int n)
{	idx[0]=-1;
	for(int i=1;i<N;i++) idx[i]=idx[i-1]+(!(i&(i-1)));
	for(int i=0;i<M;i++) p[i]=(1<<i);
	for(int i=1;i<=n;i++) mx[0][i]=val[i];
	for(int i=1;p[i]<=n;i++) for(int j=1;j+p[i]-1<=n;j++)
		mx[i][j]=min(mx[i-1][j],mx[i-1][j+p[i-1]]);
}
int lcp(int x,int y)
{	x=rank[x],y=rank[y]; if(x>y) swap(x,y); if(x==y) return x-sa[x];
	x++; int k=idx[y-x+1]; return min(mx[k][x],mx[k][y-p[k]+1]);
}
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&str[i]);
	da(str,sa,rank,height,n,1000000);
	//for(int i=1;i<n;i++) printf("%d ",height[i]); printf("\n");
	int l=0,r=n,mid;
	while (l<r)
	{
		mid=(l+r+1)>>1;
		int flag=0,sum=0,i=0,j=1;
		while (i<n && j<n)
		{
			while (j<n && height[j]>=mid) j++;
			if(j-i>=k) {flag=1;break;}
			i=j;
			j=i+1;
		}
		if(flag) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}