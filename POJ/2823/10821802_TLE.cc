#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 1000010
#define M 100010
int heap1[N],heap2[N],pos1[N],pos2[N];
int n,k;
int ans1[N],ans2[N];
void build_down1(int father)
{
	int son=father*2;
	while (son<=k)
	{
		if(heap1[son+1]>heap1[son] && son+1<=k)son++;
		if(heap1[son]>heap1[father])
		{
			swap(heap1[son],heap1[father]);
			swap(pos1[son],pos1[father]);
		}
		else return;
		father=son;
		son=father*2;
	}
}
void build_down2(int father)
{
	int son=father*2;
	while (son<=k)
	{
		if(heap2[son+1]<heap2[son] && son+1<=k)son++;
		if(heap2[son]<heap2[father])
		{
			swap(heap2[son],heap2[father]);
			swap(pos2[son],pos2[father]);
		}
		else return;
		father=son;
		son=father*2;
	}
}
void build_up1(int son)
{
	int father=son/2;
	while (father>=1)
	{
		if(heap1[father]<heap1[son])
		{
			swap(heap1[father],heap1[son]);
			swap(pos1[father],pos1[son]);
		}
		else break;
		son=father;
		father=son/2;
	}
}
void build_up2(int son)
{
	int father=son/2;
	while (father>=1)
	{
		if(heap2[father]>heap2[son])
		{
			swap(heap2[father],heap2[son]);
			swap(pos2[father],pos2[son]);
		}
		else break;
		son=father;
		father=son/2;
	}
}
int main ()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++)
	{
		pos1[i]=pos2[i]=i;
		scanf("%d",&heap1[i]);
		heap2[i]=heap1[i];
	}
	for(i=k/2;i>=1;i--)
	{
		build_down1(i);
		build_down2(i);
	}
	ans1[++ans1[0]]=heap1[1];
	ans2[++ans2[0]]=heap2[1];
	for(i=k+1;i<=n;i++)
	{
		int a,b1,b2,zzz=(i%k==0?k:i%k);
		scanf("%d",&a);
		b1=heap1[pos1[zzz]];
		b2=heap2[pos2[zzz]];
		pos1[zzz];
		pos2[zzz];
		heap1[pos1[zzz]]=heap2[pos2[zzz]]=a;
		if(a>b1)build_up1(pos1[zzz]);
		else build_down1(pos1[zzz]);
		if(a<b2)build_up2(pos2[zzz]);
		else build_down2(pos2[zzz]);
		ans1[++ans1[0]]=heap1[1];
		ans2[++ans2[0]]=heap2[1];
	}
	for(i=1;i<=ans2[0];i++)
	{
		printf("%d",ans2[i]);
		if(i<ans2[0])printf(" ");
		else printf("\n");
	}
	for(i=1;i<=ans1[0];i++)
	{
		printf("%d",ans1[i]);
		if(i<ans1[0])printf(" ");
		else printf("\n");
	}
	
	return 0;
}