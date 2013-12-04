#include <cstdio>
#include <cstring>

long a[10001],b[50001],c[50001],i,j,k,p[10001],sum[10001],out[10001];
long dfn[10001],low[10001],stack[10001];
int instack[10001],vis[10001];
long tot,step,point,count,n,m;

void tarjan(long s)
{
    long i,j;
    
   	step++;
	low[s]=dfn[s]=step;
	vis[s]=1;
	stack[++tot]=s;
	instack[s]=1;
	for(i=a[s];i;i=b[i])
	{
		if(! vis[c[i]])
		{
			tarjan(c[i]);
			low[s]=low[s]<low[c[i]]?low[s]:low[c[i]];
		}
		else
		if(instack[c[i]])low[s]=low[s]<dfn[c[i]]?low[s]:dfn[c[i]];
	}
    if(dfn[s]==low[s])
    {
    	point++;
        do{
            j=stack[tot--];
            p[j]=point;
            sum[point]++;
        }while(j!=s);
    }
}
  
int main ()
{
	while (scanf("%ld%ld",&n,&m)!=EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		memset(vis,0,sizeof(vis));
		memset(out,0,sizeof(out));
		memset(sum,0,sizeof(sum));
		memset(instack,0,sizeof(instack));
		count=tot=step=point=0;
		for(i=1;i<=m;i++)
		{
			scanf("%ld%ld",&j,&k);
			c[i]=k;
			b[i]=a[j];
			a[j]=i;
		}
		for(i=1;i<=n;i++)
			if(! vis[i])tarjan(i);
		for(i=1;i<=n;i++)
		for(j=a[i];j;j=b[j])
			if(p[i]!=p[c[j]]) out[p[i]]++;
		for(i=1;i<=point;i++)
			if(out[i]==0)
			{
				count++;
				k=i;
			}
		if(count!=1)printf("0\n");
		else printf("%ld\n",sum[k]);
	}
	
	return 0;
}