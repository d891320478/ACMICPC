#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,x1,y1,x2,y2;
struct ff
{
	int x,y;
}a[5000],b,c,d;
int sum[5000];

int f(ff b,ff c,ff d)
{
	return ((c.x-b.x)*(d.y-b.y)-(d.x-b.x)*(c.y-b.y));
}

int cmp(const ff &a,const ff &b)
{
	if(a.x<b.x)return 1;
	if(a.x>b.x)return 0;
	if(a.y<b.y)return 1;
	return 0;
}

void search(int s,int t)
{
	int mid,ans;
	while(s<t)
	{
		mid=(s+t)/2;
		b.x=a[mid].y; c.x=a[mid].x;
		ans=f(b,c,d);
		if(ans<0)s=mid+1;
		else t=mid;
	}
	sum[s]++;
}

int main ()
{
	int i;
	while (scanf("%d",&n) && n)
	{
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		memset(sum,0,sizeof(sum));
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		a[n].x=a[n].y=x2;
		sort(a,a+n,cmp);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&d.x,&d.y);
			b.y=y2; c.y=y1;
			b.x=a[0].y; c.x=a[0].x;
			search(0,n);
		}
		sort(sum,sum+n+1);
		i=0;
		while(i<=n && sum[i]==0)i++;
		printf("Box\n");
		while(i<=n)
		{
			int j=i;
			while(j<=n && sum[j+1]==sum[j])j++;
			printf("%d: %d\n",sum[j],j-i+1);
			i=j+1;
		}
	}
	
	return 0;
}