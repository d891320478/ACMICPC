#include <cstdio>
#define eps 1e-8
struct point
{
	double x,y;
};
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int t,n,i,j,k;
point a[101],b[101];
point u,v;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
		bool flag;
		for(i=0;i<n;i++)
		{
			u=a[i]; flag=0;
			for(j=0;j<n;j++)
			{
				v=a[j];
				if(u.x!=v.x || u.y!=v.y)
				{
					flag=1;
					for(k=0;k<n;k++)
						if(xmult(a[k],v,u)*xmult(v,b[k],u)<-eps)
						{
							flag=0;
							break;
						}
					if(flag)break;
				}
				v=b[j];
				if(u.x!=v.x || u.y!=v.y)
				{
					flag=1;
					for(k=0;k<n;k++)
						if(xmult(a[k],v,u)*xmult(v,b[k],u)<-eps)
						{
							flag=0;
							break;
						}
					if(flag)break;
				}
			}
			if(flag)break;
			u=b[i];
			for(j=0;j<n;j++)
			{
				v=a[j];
				if(u.x!=v.x || u.y!=v.y)
				{
					flag=1;
					for(k=0;k<n;k++)
						if(xmult(a[k],v,u)*xmult(v,b[k],u)<-eps)
						{
							flag=0;
							break;
						}
					if(flag)break;
				}
				v=b[j];
				if(u.x!=v.x || u.y!=v.y)
				{
					flag=1;
					for(k=0;k<n;k++)
						if(xmult(a[k],v,u)*xmult(v,b[k],u)<-eps)
						{
							flag=0;
							break;
						}
					if(flag)break;
				}
			}
			if(flag)break;
		}
		if(flag)printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}