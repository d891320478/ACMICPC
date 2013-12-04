#include <cstdio>
#include <iostream>
using namespace std;
int n,m,a[10010],p,q,x,y,i;
int main ()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while (m>0)
		{
			p=n-1;		while (a[p]>a[p+1]) p--;
			if(p>0)
			{
				q=n;			while(a[q]<a[p]) q--;
				swap(a[p],a[q]);			x=p+1;		y=n;
				while (x<y)
				{		swap(a[x],a[y]);		x++;y--;		}
			}
			if(m>0)
			{
				int flag=1;
				for(i=1;i<=n;i++)
					if(a[i]!=n-i+1)
					{
						flag=0;
						break;
					}
				if(flag) for(i=1;i<=n;i++) a[i]=i;
			}
			m--;
		}
		for(i=1;i<n;i++) printf("%d ",a[i]);	printf("%d\n",a[n]);
	}
	return 0;
}