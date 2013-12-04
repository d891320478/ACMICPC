#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

struct f
{
    double x,y;
}l[40],a1,b1;
double d[40],a[40][40];
int last,n;

double mul(f p0,f p1,f p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool intersect(f s1,f e1,f s2,f e2)
{
	return (max(s1.x,e1.x)>=min(s2.x,e2.x) && max(s2.x,e2.x)>=min(s1.x,e1.x) && 
			max(s1.y,e1.y)>=min(s2.y,e2.y) && max(s2.y,e2.y)>=min(s1.y,e1.y) && 
			mul(s1,s2,e1)*mul(s1,e1,e2)>0 && mul(s2,s1,e2)*mul(s2,e2,e1)>0);
}

int main()
{
	double x,y[5];
	while(scanf("%d",&n))
	{
		if(n==-1)break;
		memset(a,0,sizeof(a));
		last=4*n+1;
		l[0].x=0,l[0].y=5;
		l[last].x=10,l[last].y=5;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&x,&y[1],&y[2],&y[3],&y[4]);
			for(int j=1;j<=4;j++)
			{
				l[(i-1)*4+j].x=x;
				l[(i-1)*4+j].y=y[j];
			}			
		}
		for(int i=0;i<=last;i++)
		for(int j=i+1;j<=last;j++)
		if(l[i].x!=l[j].x)
		{
			int flag=1;
			for(int k=1;k<last;k+=4)
			{
				a1.x=l[k].x; a1.y=0;
				b1.x=l[k].x; b1.y=10;
				if(intersect(l[i],l[j],a1,l[k])){flag=0;break;}
				if(intersect(l[i],l[j],l[k+1],l[k+2])){flag=0;break;}
				if(intersect(l[i],l[j],l[k+3],b1)){flag=0;break;}
			}
			if(flag)a[i][j]=sqrt(pow(l[i].x-l[j].x,2.0)+pow(l[i].y-l[j].y,2.0));
			else a[i][j]=1e10;
		}
		for(int i=1;i<=last;i++)
			d[i]=a[0][i];
		d[0]=0;
		bool u[40]={1};
		for(int i=1;i<=last;i++)
		{
			double maxx=1e10;
			int v;
			for(int j=0;j<=last;j++)
				if(!u[j] && d[j]<maxx)
				{
					v=j;
					maxx=d[j];
				}
			if(v==last)break;
			u[v]=1;
			for(int j=0;j<=last;j++)
				if(! u[j] && d[j]>d[v]+a[v][j])
					d[j]=d[v]+a[v][j];
		}
		printf("%.2f\n",d[last]);
	}
	
	return 0;
}
