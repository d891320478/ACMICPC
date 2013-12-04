#include <cstdio>
#include <algorithm>
using namespace std;
#define maxm 1000010
int id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxm];
int e[maxm][2];
int cmp(const int &i,const int &j){return ew[i]<ew[j];}
int find(int x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}
int kruskal()
{
    int i,j=-1,p,x,y,value;
    for(i=0;i<m;i++) 	id[i]=i;
    sort(id,id+m,cmp);
    for(i=1;i<=n;i++)	pnt[i]=i;
    for(i=1;i<n;i++)
    {
        while(1)
        {
			p=id[++j];   if(j>=m)return 0;
			x=find(eu[p]);   y=find(ev[p]);	if(x!=y)break;
        }
        value=ew[p];
        e[i][0]=eu[p];
        e[i][1]=ev[p];
        pnt[y]=x;
    }
    printf("%d %d\n",value,n-1);
    for(i=1;i<n;i++)
    	printf("%d %d\n",e[i][0],e[i][1]);
    return 1;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&eu[i],&ev[i],&ew[i]);
	kruskal();
	
	return 0;
}