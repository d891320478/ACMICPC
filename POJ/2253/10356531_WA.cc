#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 210
#define maxm 40010
long id[maxm],eu[maxm],ev[maxm],n,m,pnt[maxn];
double ew[maxm],ans;
int cmp(const long &i,const long &j){return ew[i]<ew[j];}
long find(long x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    long i,j=-1,p,x,y;
    for(i=0;i<m;i++) 	id[i]=i;
    sort(id,id+m,cmp);
    for(i=0;i<n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
			p=id[++j];            
			if(j>=m)return 0;            
			x=find(eu[p]);            
			y=find(ev[p]);
			if(x!=y)break;
			if(x==1 && y==2 && pnt[1]==pnt[2])return 1;
        }
        ans=ew[p];
        pnt[y]=x;
    }
    return 1;
}
struct point
{
	double x,y;
}p[maxn];
double Dis(point a,point b)
{
	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));
}
int main()
{
	int tt=0,i,j;
	while (scanf("%ld",&n) && n)
	{
		tt++;
		m=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			for(j=1;j<i;j++)
			{
				eu[m]=i;
				ev[m]=j;
				ew[m]=Dis(p[i],p[j]);
				m++;
			}
		}
		kruskal();
		if(tt>1)printf("\n");
		printf("Scenario #%d\nFrog Distance = %.3f\n",tt,ans);
	}
	
	return 0;
}