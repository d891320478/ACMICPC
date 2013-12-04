#include<stdio.h>

int g[101][101],c[101][101];
int n,m, step=0,tot=0;
int dfn[101],low[101],stack[101];
int instack[101],vis[101];
int a[101][101],point,b[101],into[101],out[101];

void tarjan(int s)
{
    int i,j;
    
   	step++;
	low[s]=dfn[s]=step;
	vis[s]=1;
	stack[++tot]=s;
	instack[s]=1;
	for(i=1;i<=g[s][0];i++)
	{
		if(! vis[g[s][i]])
		{
			tarjan(g[s][i]);
			low[s]=low[s]<low[g[s][i]]?low[s]:low[g[s][i]];
		}
		else
		if(instack[g[s][i]])low[s]=low[s]<dfn[g[s][i]]?low[s]:dfn[g[s][i]];
	}
    if(dfn[s]==low[s])
    {
    	point++;
        do{
            j=stack[tot--];
            instack[j]=0;
            b[j]=point;
        }while(j!=s);
    }
}

int main()
{
    int i,j,k;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        while(scanf("%d",&j) && j)
        {
        	g[i][++g[i][0]]=j;
        	c[i][j]=1;
        }
    for(i=1;i<=n;i++) if(dfn[i]==0)tarjan(i);
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=g[i][0];j++)
    		if(b[i]!=b[g[i][j]])
    		{
    			into[b[g[i][j]]]++;
    			out[b[i]]++;
    		}
    }
    int count1=0,count2=0;
    for(i=1;i<=point;i++)
    {
    	if(into[i]==0)count1++;
    	if(out[i]==0)count2++;
    }
    printf("%d\n",count1);
    if(point==1)printf("0\n");
    else printf("%d\n",count1>count2?count1:count2);
    
    return 0;
}
