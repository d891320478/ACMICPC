#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t,n,ans,maxx,i;
struct f
{
	int x,y;
}a[201];

int cmp(const f &a,const f &b)
{
	if(a.x<b.x)return 1;
	if(a.x>b.x)return 0;
	if(a.y<b.y)return 1;
	return 0;
}

int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
		}
		sort(a,a+n,cmp);
		ans=-1;
		while (1)
		{
			ans++;
			for(i=0;i<n;i++) if(a[i].x)break;
			if(i>=n)break;
			maxx=a[i].y;
			a[i].x=a[i].y=0;
			for(i++;i<n;i++)
				if(a[i].x>maxx && maxx%2==0 || a[i].x>maxx+1 && maxx%2==1)
				{
					maxx=a[i].y;
					a[i].x=a[i].y=0;
				}
		}
		printf("%d\n",ans*10);
	}
	
	return 0;
}