#include <cstdio>
#include <iostream>
using namespace std;
#define N 1000010
int pos1[N],pos2[N];
struct Heap
{
	int key,opp;
}heap1[N],heap2[N];
int n,k;
int ans1[N],ans2[N];
void build_down1(int father)
{
	int son=father*2;
	while (son<=k)
	{
		if(heap1[son+1].key>heap1[son].key && son+1<=k)son++;
		if(heap1[son].key>heap1[father].key)
		{
			swap(pos1[heap1[son].opp],pos1[heap1[father].opp]);
			swap(heap1[son],heap1[father]);
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
		if(heap2[son+1].key<heap2[son].key && son+1<=k)son++;
		if(heap2[son].key<heap2[father].key)
		{
			swap(pos2[heap2[son].opp],pos2[heap2[father].opp]);
			swap(heap2[son],heap2[father]);
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
		if(heap1[father].key<heap1[son].key)
		{
			swap(pos1[heap1[father].opp],pos1[heap1[son].opp]);
			swap(heap1[father],heap1[son]);
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
		if(heap2[father].key>heap2[son].key)
		{
			swap(pos2[heap2[father].opp],pos2[heap2[son].opp]);
			swap(heap2[father],heap2[son]);
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
		pos1[i]=pos2[i]=heap1[i].opp=i;
		scanf("%d",&heap1[i].key);
		heap2[i]=heap1[i];
	}
	for(i=k/2;i>=1;i--)
	{
		build_down1(i);
		build_down2(i);
	}

	/*for(j=1;j<=k;j++) printf("%d ",heap1[j]);
		printf("\n");
	for(j=1;j<=k;j++) printf("%d ",pos1[j]);
		printf("\n\n");*/
		
	ans1[++ans1[0]]=heap1[1].key;
	ans2[++ans2[0]]=heap2[1].key;
	for(i=k+1;i<=n;i++)
	{
		int a,b1,b2,zzz=(i%k==0?k:i%k);
		scanf("%d",&a);
		b1=heap1[pos1[zzz]].key;
		b2=heap2[pos2[zzz]].key;
		heap1[pos1[zzz]].key=heap2[pos2[zzz]].key=a;
		
		/*for(j=1;j<=k;j++) printf("%d ",heap1[j]);
		printf("\n");
		for(j=1;j<=k;j++) printf("%d ",pos1[j]);
		printf("\n");*/
		
		if(a>b1)build_up1(pos1[zzz]);
		else build_down1(pos1[zzz]);
		if(a<b2)build_up2(pos2[zzz]);
		else build_down2(pos2[zzz]);
		ans1[++ans1[0]]=heap1[1].key;
		ans2[++ans2[0]]=heap2[1].key;
		
		/*for(j=1;j<=k;j++) printf("%d ",heap1[j]);
		printf("\n");
		for(j=1;j<=k;j++) printf("%d ",pos1[j]);
		printf("\n\n");*/
		
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