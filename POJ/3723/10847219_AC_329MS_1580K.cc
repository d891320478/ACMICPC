#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define ABS(x) (x)>=0?(x):-(x)
#define N 20010
#define M 50010
long id[M],eu[M],ev[M],ew[M],n,m,r,pnt[N];
int cmp(const long &i,const long &j){return ew[i]>ew[j];}
long find(long x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    long i,j=-1,p,x,y,value=0;
    for(i=0;i<m;i++) 	id[i]=i;
    sort(id,id+m,cmp);
    for(i=0;i<n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
			p=id[++j];   if(j>=m) break;
			x=find(eu[p]);   y=find(ev[p]);	if(x!=y)break;
        }
        if(j>=m) break;
        value+=ew[p];		pnt[y]=x;
    }
    cout<<n*10000-value<<endl;
    return 0;
}
int main ()
{
	int ttt,i;
	scanf("%d",&ttt);
	while (ttt--)
	{
		scanf("%d%d%d",&n,&r,&m);
		for(i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			eu[i]=u;
			ev[i]=v+n;
			ew[i]=w;
		}
		n=n+r;
		kruskal();
	}
	
	return 0;
}