#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 30
#define maxm 1000
long id[maxm],eu[maxm],ev[maxm],ew[maxm],n,m,pnt[maxn];
int cmp(const long &i,const long &j){return ew[i]<ew[j];}
long find(long x){if(x!=pnt[x])pnt[x]=find(pnt[x]);return pnt[x];}

int kruskal()
{
    long i,j=-1,p,x,y,value=0;
    
	for(i=0;i<m;i++) id[i]=i;
    sort(id,id+m,cmp);
    for(i=0;i<n;i++) pnt[i]=i;
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
        value+=ew[p];
		pnt[y]=x;
    }
    printf("%ld\n",value);
    
    return 1;
}

int main()
{
	char ch,c;
   	int u,v,j,k,l;
   	
	while(scanf("%ld%c",&n,&ch)!=EOF && n)
	{
	    m=0;
	    for(long i=0;i<n-1;i++)
	    {
	        scanf("%c %d%c",&ch,&j,&c);
	        u=ch-'A';
	        for(k=1;k<=j;k++)
	        {
	            scanf("%c %d%c",&c,&l,&ch);
	            v=c-'A';
	            eu[m]=u;
	            ev[m]=v;
	            ew[m]=l;
	            m++;
	        }
	    }
	    kruskal();
	}
	
	return 0;
}