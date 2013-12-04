#include <stdio.h>

int l,r,c;

int main()
{
	while(scanf("%d%d%d",&l,&r,&c))
	{
		if(l==0 && r==0 && c==0)break;
		
		char s[32][32][32],ch1,ch2;
		int i,j,k,x,y,z,d,e,g;
		struct
		{
			int a,b,c,t;
		}f[30000]={0};
		int u[32][32][32]={0};
		int head=0,tail=0;
		
		for(i=0;i<l;i++)
		{
			for(j=0;j<r;j++)
				scanf("%s",s[i][j]);
			scanf("%c,%c",&ch1,&ch2);
		}
		for(i=0;i<l;i++)
		for(j=0;j<r;j++)
		for(k=0;k<c;k++)
		{
			if(s[i][j][k]=='S')
			{
				f[0].a=i;
				f[0].b=j;
				f[0].c=k;
				f[0].t=0;
				u[i][j][k]=1;
			}
			if(s[i][j][k]=='E')
			{
				x=i;y=j;z=k;
				s[i][j][k]='.';
			}
		}
		while(head<=tail)
		{
			d=f[head].a; e=f[head].b; g=f[head].c;
			if(d-1>=0)
			if(s[d-1][e][g]=='.')
			if(! u[d-1][e][g])
			{
				u[d-1][e][g]=1;
				tail++;
				f[tail].a=d-1;
				f[tail].b=e;
				f[tail].c=g;
				f[tail].t=f[head].t+1;
				if(d-1==x && e==y && g==z)break;
			}
			if(d+1<l)
			if(s[d+1][e][g]=='.')
			if(! u[d+1][e][g])
			{
				u[d+1][e][g]=1;
				tail++;
				f[tail].a=d+1;
				f[tail].b=e;
				f[tail].c=g;
				f[tail].t=f[head].t+1;
				if(d+1==x && e==y && g==z)break;
			}
			if(e-1>=0)
			if(s[d][e-1][g]=='.')
				if(! u[d][e-1][g])
				{
					u[d][e-1][g]=1;
					tail++;
					f[tail].a=d;
					f[tail].b=e-1;
					f[tail].c=g;
					f[tail].t=f[head].t+1;
					if(d==x && e-1==y && g==z)break;
				}
			if(e+1<r)
			if(s[d][e+1][g]=='.')
				if(! u[d][e+1][g])
				{
					u[d][e+1][g]=1;
					tail++;
					f[tail].a=d;
					f[tail].b=e+1;
					f[tail].c=g;
					f[tail].t=f[head].t+1;
					if(d==x && e+1==y && g==z)break;
				}
			if(g-1>=0)
			if(s[d][e][g-1]=='.')
				if(! u[d][e][g-1])
				{
					u[d][e][g-1]=1;
					tail++;
					f[tail].a=d;
					f[tail].b=e;
					f[tail].c=g-1;
					f[tail].t=f[head].t+1;
					if(d==x && e==y && g-1==z)break;
				}
			if(g+1<c)
			if(s[d][e][g+1]=='.')
				if(! u[d][e][g+1])
				{
					u[d][e][g+1]=1;
					tail++;
					f[tail].a=d;
					f[tail].b=e;
					f[tail].c=g+1;
					f[tail].t=f[head].t+1;
					if(d==x && e==y && g+1==z)break;
				}
			head++;
		}
		if(head<=tail)printf("Escaped in %d minute(s).\n",f[tail].t);
		else printf("Trapped!\n");
	}

	return 0;
}
