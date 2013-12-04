#include <cstdio>

#include <algorithm>
using namespace std;
#define maxn 30
#define maxm 1000
int id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxn];
int ans;
int cmp(const int &i,const int &j){return ew[i]<ew[j];}
int find(int x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal(int tt)
{
    int i,j=tt,p,x,y,value;
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
        }
        value=ew[p];
        pnt[y]=x;
    }
    ans=ans<value-ew[id[tt+1]]?ans:value-ew[id[tt+1]];
    return 1;
}
int main ()
{
	int i;
	freopen("1.in","r",stdin);
	while (scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0)break;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
			eu[i]--;
			ev[i]--;
			id[i]=i;
		}
	    sort(id,id+m,cmp);
	    ans=99999999;
	    if(! kruskal(-1))printf("-1\n");
	    else
	    {
	    	for(i=0;i<m;i++)
	    		if(! kruskal(i))break;
	    	printf("%d\n",ans);
	    }
	}
	
	return 0;
}