#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct ffff
{
	int d[6];
}a[100001];
void f(int s)
{
	int minn=100000000,i,j,b[6],c[6],anp,l;
	for(i=0;i<6;i++)
		if(minn>a[s].d[i])
		{
			minn=a[s].d[i];
			j=i;
		}
	b[0]=c[0]=minn; l=0;
	for(i=j+1;i<6;i++) b[++l]=a[s].d[i];
	for(i=0;i<j;i++) b[++l]=a[s].d[i];
	l=0;
	for(i=j-1;i>=0;i--) c[++l]=a[s].d[i];
	for(i=5;i>j;i--) c[++l]=a[s].d[i];
	for(i=0;i<6;i++)
	{
		if(b[i]<c[i]){anp=1;break;}
		if(b[i]>c[i]){anp=2;break;}
	}
	if(anp==1) for(i=0;i<6;i++) a[s].d[i]=b[i];
	else  for(i=0;i<6;i++) a[s].d[i]=c[i];
}
int cmp(const ffff &a,const ffff &b)
{
	for(int i=0;i<6;i++)
	{
		if(a.d[i]<b.d[i])return 1;
		if(a.d[i]>b.d[i])return 0;
	}
	return 1;
}
int ff(int mid,int j)
{
	for(int i=0;i<6;i++)
	{
		if(a[mid].d[i]>a[j].d[i])return 1;
		if(a[mid].d[i]<a[j].d[i])return -1;
	}
	return 0;
}
bool search(int s,int t,int i)
{
	int mid,anss;
	while(s<=t)
	{
		mid=(s+t)/2;
		anss=ff(mid,i);
		if(anss==0)return 1;
		if(anss==1)t=mid;
		else s=mid+1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<6;j++)
			scanf("%d",&(a[i].d[j]));
		f(i);
	}
	sort(a,a+n,cmp);
	bool flag;
	for(int i=0;i<n-1;i++)
	{
		flag=search(i+1,n-1,i);
		if(flag)break;
	}
	if(flag)puts("Twin snowflakes found.");
	else puts("No two snowflakes are alike.");
	
	return 0;
}
