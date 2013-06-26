#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
struct poi
{
	int x,y;
	int id;
}p[N];
int n;
int cmp(poi a,poi b)
{
	return a.x<b.x || a.x==b.x && a.y>b.y;
}
int a[N],b[N],c[N];
int search(int x)
{
	int l=1,r=a[0],mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(a[mid]<x) l=mid+1;
		else r=mid;
	}
	if(a[l]==x) return -1;
	return l;
}
int ass[N];
void findans(int x)
{
	if(x==-1) return;
	findans(c[x]);
	ass[++ass[0]]=x;
}
int main()
{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {scanf("%d%d",&p[i].x,&p[i].y);p[i].id=i;}
		sort(p+1,p+1+n,cmp);
		a[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[0]==0) {a[++a[0]]=p[i].y; b[a[0]]=p[i].id; c[p[i].id]=-1;}
			else
			{
				if(p[i].y>a[a[0]])
				{
					a[++a[0]]=p[i].y;
					b[a[0]]=p[i].id;
					c[p[i].id]=b[a[0]-1];
				}
				else
				{
					int v=search(p[i].y);
					if(v!=-1)
					{
						a[v]=p[i].y;
						b[v]=p[i].id;
						if(v>1) c[p[i].id]=b[v-1];
						else c[p[i].id]=-1;
					}
				}
			}
		}
		printf("%d\n",a[0]);
		ass[0]=0;
		findans(b[a[0]]);
		for(int i=1;i<=a[0];i++)
		{
			printf("%d",ass[i]);
			if(i<a[0]) printf(" ");
			else printf("\n");
		}
	return 0;
}
