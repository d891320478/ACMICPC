#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
struct fff
{
	int id,time,now;
}heap[3010];
int lh,kk;
string s;
int cmp(int a,int b)
{
	return heap[a].now<heap[b].now || (heap[a].now==heap[b].now && heap[a].id<heap[b].id);
}
void heap_down(int fth)
{
	int son=fth*2;
	while (son<=lh)
	{
		if(son+1<=lh) if(cmp(son+1,son)) son++;
		if(cmp(son,fth))
		{
			heap[0]=heap[fth];
			heap[fth]=heap[son];
			heap[son]=heap[0];
		}
		else break;
		fth=son;
		son=fth*2;
	}
}
int main ()
{
	while (cin>>s)
	{
		if(s=="#")break;
		lh++;
		cin>>heap[lh].id>>heap[lh].time;
		heap[lh].now=heap[lh].time;
	}
	for(int i=lh/2;i>0;i--)
		heap_down(i);
	scanf("%d",&kk);
	while (kk--)
	{
		printf("%d\n",heap[1].id);
		heap[1].now+=heap[1].time;
		heap_down(1);
	}
	
	return 0;
}