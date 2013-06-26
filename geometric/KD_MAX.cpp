//BZOJ 2626
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define N 100010
#define DD 3
struct point
{
	int z[DD],id;
	int mn[DD],mx[DD];
}p[N],ask;
struct heap
{
	long long dis;
	int id;
	heap(long long _dis,int _id) : dis(_dis),id(_id) {}
};
priority_queue<heap> Q;
bool operator < (heap a,heap b)
{
	return a.dis>b.dis || a.dis==b.dis && a.id<b.id;
}
int n,D,kk,idtp;
int diy[N];
bool operator < (point a,point b)
{
	return a.z[idtp]<b.z[idtp];
}
void build_kd(int l,int r,int k)
{
	if(l>r) return;
	int mid=l+r>>1;
	idtp=diy[mid]=k+1;
	nth_element(p+l,p+mid,p+r+1);
	build_kd(l,mid-1,k^1);
	build_kd(mid+1,r,k^1);
	for(int i=1;i<=D;i++)
	{
		p[mid].mx[i]=p[mid].mn[i]=p[mid].z[i];
		if(l<=mid-1)
		{
			p[mid].mx[i]=max(p[mid].mx[i],p[(l+mid-1)>>1].mx[i]);
			p[mid].mn[i]=min(p[mid].mn[i],p[(l+mid-1)>>1].mn[i]);
		}
		if(mid+1<=r)
		{
			p[mid].mx[i]=max(p[mid].mx[i],p[(mid+1+r)>>1].mx[i]);
			p[mid].mn[i]=min(p[mid].mn[i],p[(mid+1+r)>>1].mn[i]);
		}
	}
}
inline long long sqr(int x)
{
	return static_cast<long long>(x)*x;
}
inline long long dist(point a,point b)
{
	long long ans=0;
	for(int i=1;i<=D;i++)
		ans+=sqr(a.z[i]-b.z[i]);
	return ans;
}
inline long long calc(int mid)
{
	long long ans=0;
	for(int i=1;i<=D;i++)
		ans+=sqr(max(abs(p[mid].mn[i]-ask.z[i]),abs(p[mid].mx[i]-ask.z[i])));
	return ans;
}
void find(int l,int r)
{
	int mid=l+r>>1;
	heap tmp(dist(ask,p[mid]),p[mid].id);
	if(Q.size()<(unsigned)kk) Q.push(tmp);
	else if(tmp<Q.top()) Q.pop(),Q.push(tmp);
	int l1=l,r1=mid-1,l2=mid+1,r2=r;
	if(ask.z[diy[mid]]<p[mid].z[diy[mid]]) swap(l1,l2),swap(r1,r2);
	if(l1<=r1) if(Q.size()<(unsigned)kk || calc(l1+r1>>1)>=Q.top().dis) find(l1,r1);
	if(l2<=r2) if(Q.size()<(unsigned)kk || calc(l2+r2>>1)>=Q.top().dis) find(l2,r2);
}
int main ()
{
	scanf("%d",&n);
	D=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=D;j++)
			scanf("%d",&p[i].z[j]);
		p[i].id=i;
	}
	build_kd(1,n,1);
	int _;
	scanf("%d",&_);
	while (_--)
	{
		for(int j=1;j<=D;j++)
			scanf("%d",&ask.z[j]);
		scanf("%d",&kk);
		while (! Q.empty()) Q.pop();
		find(1,n);
		printf("%d\n",Q.top().id);
	}
	return 0;
}
