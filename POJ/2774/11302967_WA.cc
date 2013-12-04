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
#define N 200010
#define M 20
int wx[N],wy[N],wss[N],wv[N];
bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int s[],int sa[],int rank[],int height[],int n,int m)
{
	int *x=wx,*y=wy,p;
	int i,j,k;
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
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	for(i=0;i<n;i++) rank[sa[i]]=i;
	for(i=j=k=0;i<n;height[rank[i++]]=k)
		if(rank[i]>0)
		for(k?k--:0,j=sa[rank[i]-1];i+k<n && j+k<n && s[i+k]==s[j+k];k++);
}
char s[N];
int str[N],sa[N],rank[N],height[N];
void init(char *s)
{
	int len=strlen(s);
	for(int i=0;i<=len;i++)
		str[i]=s[i];
	da(str,sa,rank,height,len,128);
}
char st1[N],st2[N];
int main()
{
	scanf("%s%s",st1,st2);
	int l1=strlen(st1),l2=strlen(st2);
	st1[l1]='*';
	for(int i=0;i<l2;i++)
		st1[l1+1+i]=st2[i];
	st1[l1+l2+1]=0;
	init(st1);
	int ans=0;
	for(int i=1;i<=l1+l2;i++)
	{
		int x=rank[i-1],y=rank[i];
		if(x>y) swap(x,y);
		if(x<l1 && y>=l1) ans=max(ans,height[i]);
	}
	printf("%d\n",ans);
	return 0;
}