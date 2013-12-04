#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 100010
#define M 20
//至少log(N,2)+1
int n,m;
int a[N],val[M][N],tol[M][N];//val记录每次划分时的元素，tol记录第i层第j个之前包括第j个有多少个被分到左儿子
void build(int l,int r,int row)
{
	if(l==r) return;
	int mid=(l+r)>>1,i,s=l,e=mid+1;
	int ls=mid+1-l;//和a[mid]相等且分在左儿子的元素个数
	for(i=l;i<=r;i++)
		if(val[row][i]<a[mid]) ls--;
	for(i=l;i<=r;i++)
	{
		tol[row][i]=(i==l?0:tol[row][i-1]);
		if(val[row][i]<a[mid])
		{
			val[row+1][s++]=val[row][i];
			tol[row][i]++;
		}
		else
		if(val[row][i]>a[mid]) val[row+1][e++]=val[row][i];
		else if(ls)
		{
			val[row+1][s++]=val[row][i];
			tol[row][i]++;
			ls--;
		}
		else val[row+1][e++]=val[row][i];
	}
	build(l,mid,row+1);
	build(mid+1,r,row+1);
}
int query(int l,int r,int k,int L,int R,int row)
{
	if(l==r) return val[row][l];
	int ll=(l==L?0:tol[row][l-1]);
	int li=tol[row][r]-ll;
	int mid=(L+R)>>1;
	if(k<=li) return query(L+ll,L+ll+li-1,k,L,mid,row+1);
	int rl=l-L-ll;
	int ri=r-l+1-li;
	return query(mid+1+rl,mid+1+rl+ri-1,k-li,mid+1,R,row+1);
}
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			val[1][i]=a[i];
		}
		sort(a+1,a+1+n);
		build(1,n,1);
		while (m--)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			printf("%d\n",query(u,v,w,1,n,1));
		}
	}
	return 0;
}