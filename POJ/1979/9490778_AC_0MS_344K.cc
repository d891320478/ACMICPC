#include<stdio.h>
#include<string.h>

int n,m,sum;
char s[22][22],ch;
int i,j;
int x[402][2],head,tail;
int u[22][22];

int main()
{
   
    scanf("%d %d%c",&m,&n,&ch);
    while(m>0 && n>0)
    {
    	memset(u,0,sizeof(u));
    	head=tail=0;
    	sum=1;
    	for(i=0;i<n;i++)
    		gets(s[i]);
    	for(i=0;i<n;i++)
    	for(j=0;j<m;j++)
        if(s[i][j]=='@')
        {
        	x[0][0]=i;
        	x[0][1]=j;
        	u[i][j]=1;
        }
    	while(head<=tail)
    	{
    	    if(x[head][0]-1>=0)
    	    if(s[x[head][0]-1][x[head][1]]=='.')
    	    if(! u[x[head][0]-1][x[head][1]])
    	    {
    	        u[x[head][0]-1][x[head][1]]=1;
    	        tail++;
    	        x[tail][0]=x[head][0]-1;
    	        x[tail][1]=x[head][1];
    	        sum++;
    	    }
			if(x[head][1]-1>=0)
    	    if(s[x[head][0]][x[head][1]-1]=='.')
    	    if(! u[x[head][0]][x[head][1]-1])
    	    {
    	        u[x[head][0]][x[head][1]-1]=1;
    	        tail++;
    	        x[tail][0]=x[head][0];
    	        x[tail][1]=x[head][1]-1;
    	        sum++;
    	    }
    	    if(x[head][0]+1<n)
    	    if(s[x[head][0]+1][x[head][1]]=='.')
    	    if(! u[x[head][0]+1][x[head][1]])
    	    {
    	        u[x[head][0]+1][x[head][1]]=1;
    	        tail++;
    	        x[tail][0]=x[head][0]+1;
    	        x[tail][1]=x[head][1];
    	        sum++;
    	    }
    	    if(x[head][1]+1<m)
    	    if(s[x[head][0]][x[head][1]+1]=='.')
    	    if(! u[x[head][0]][x[head][1]+1])
    	    {
    	        u[x[head][0]][x[head][1]+1]=1;
    	        tail++;
    	        x[tail][0]=x[head][0];
    	        x[tail][1]=x[head][1]+1;
    	        sum++;
    	    }
    	    head++;
    	}
    	printf("%d\n",sum);
    	scanf("%d %d%c",&m,&n,&ch);
    }
    
	return 0;
}
