#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 1010
#define maxm 1000010
long id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxn];
int cmp(const long &i,const long &j){return ew[i]>ew[j];}
long find(long x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    long i,j=-1,p,x,y,value=0;
    for(i=0;i<m;i++) 	id[i]=i;
    sort(id,id+m,cmp);
    for(i=1;i<=n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
	p=id[++j];            if(j>=m)return 0;            x=find(eu[p]);            y=find(ev[p]);
	if(x!=y)break;
        }
		pnt[y]=x;
		x=find(1);
		y=find(n);
		if(x==y)return ew[p];
    }
}
int main ()
{
	int t,tt,i;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
		if(tt>1)printf("\n");
		printf("Scenario #%d:\n%d\n",tt,kruskal());
	}
	
	return 0;
}