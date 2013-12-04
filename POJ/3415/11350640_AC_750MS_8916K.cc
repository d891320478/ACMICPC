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
char s[N];	int str[N],sa[N],rank[N],height[N];
void init(char *s)
{ int len=strlen(s); for(int i=0;i<=len;i++) str[i]=s[i];
  da(str,sa,rank,height,len,128); }
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
char st[N],a1[N];
int k,top;
long long sta[N],sm[N];
long long sum,ans;
int main()
{
	while (scanf("%d",&k) && k)
	{
		scanf("%s%s",st,a1);
		int l1=strlen(st),l2=strlen(a1);
		st[l1]='$';
		for(int i=0;i<=l2;i++)
			st[l1+1+i]=a1[i];
		init(st);
		top=0;
		sum=ans=0;
		for(int i=1;i<l1+l2+1;i++)
		{
			if(height[i]<k) top=sum=0;
			else
			{
				if(top)
				if(sta[top]>height[i])
				{
					sum-=(sta[top]-height[i])*sm[top];
					sta[top]=height[i];
				}
				while (top>1)
				{
					if(sta[top-1]>height[i])
					{
						sum-=(sta[top-1]-height[i])*sm[top-1];
						sta[top-1]=height[i];
						sm[top-1]+=sm[top];
						top--;
					}
					else break;
				}
				if(sa[i-1]>l1)
				{
					sum+=height[i]-k+1;
					if(sta[top]==height[i]) sm[top]++;
					else
					{
						sta[++top]=height[i];
						sm[top]=1;
					}
				}
				if(sa[i]<l1) ans+=sum;
			}
		}
		top=sum=0;
		for(int i=1;i<l1+l2+1;i++)
		{
			if(height[i]<k) top=sum=0;
			else
			{
				if(top)
				if(sta[top]>height[i])
				{
					sum-=(sta[top]-height[i])*sm[top];
					sta[top]=height[i];
				}
				while (top>1)
				{
					if(sta[top-1]>height[i])
					{
						sum-=(sta[top-1]-height[i])*sm[top-1];
						sta[top-1]=height[i];
						sm[top-1]+=sm[top];
						top--;
					}
					else break;
				}
				if(sa[i-1]<l1)
				{
					sum+=height[i]-k+1;
					if(sta[top]==height[i]) sm[top]++;
					else
					{
						sta[++top]=height[i];
						sm[top]=1;
					}
				}
				if(sa[i]>l1) ans+=sum;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}