#include <cstdio>
#include <algorithm>
using namespace std;

int t,n,ans,i,b,c;
struct f
{
	int l,w;
}a[5001];

int cmp(const f &a,const f &b)
{
	if(a.l>b.l)return 1;
	if(a.l<b.l)return 0;
	if(a.w>b.w)return 1;
	return 0;
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].l,&a[i].w);
		sort(a,a+n,cmp);
		ans=-1;
		while (1)
		{
			ans++;
			for(i=0;i<n;i++) if(a[i].l)break;
			if(i>=n)break;
			b=a[i].l; c=a[i].w;
			a[i].l=a[i].w=0;
			for(i++;i<n;i++)
				if(a[i].l)
				if(a[i].l<=b && a[i].w<=c)
				{
					b=a[i].l; c=a[i].w;
					a[i].l=a[i].w=0;
				}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}