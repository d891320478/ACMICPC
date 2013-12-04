#include <cstdio>

int a[12][12],n,i,j,t=0;
char s[50][50];

void f(int x,int y)
{
	int i,j;
	
	if(s[x][y-2]==' ')
	{
		if(x-2>0)
		if(s[x-2][y]==' ')
		{
			s[x][y-2]=s[x-2][y]='H';
			s[x][y-1]='-';
			s[x-1][y]='|';
			return;
		}
		if(x+2<4*n-2)
		if(s[x+2][y]==' ')
		{
			s[x][y-2]=s[x+2][y]='H';
			s[x][y-1]='-';
			s[x+1][y]='|';
			return;
		}
	}
	if(s[x][y+2]==' ')
	{
		if(s[x-2][y]==' ')
		{
			s[x][y+2]=s[x-2][y]='H';
			s[x][y+1]='-';
			s[x-1][y]='|';
			return;
		}
		if(s[x+2][y]==' ')
		{
			s[x][y+2]=s[x+2][y]='H';
			s[x][y+1]='-';
			s[x+1][y]='|';
			return;
		}
	}
}

int main ()
{
	while(scanf("%d",&n) && n)
	{
		t++;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		for(i=0;i<=4*n-2;i++)
		for(j=0;j<=4*n+2;j++)
			s[i][j]=' ';
		for(i=0;i<=4*n+2;i++)
			s[0][i]=s[4*n-2][i]='*';
		for(i=1;i<=4*n-3;i++)
			s[i][0]=s[i][4*n+2]='*';
		for(i=1;i<=4*n-3;i+=4)
		for(j=3;j<=4*n+1;j+=4)
			s[i][j]='O';
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			{
				s[4*i-3][4*j-2]=s[4*i-3][4*j]='-';
				s[4*i-3][4*j-3]=s[4*i-3][4*j+1]='H';
			}
			else
			if(a[i][j]==-1)
			{
				s[4*i-4][4*j-1]=s[4*i-2][4*j-1]='|';
				s[4*i-5][4*j-1]=s[4*i-1][4*j-1]='H';
			}
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(! a[i][j]) f(4*i-3,4*j-1);
		printf("Case %d:\n\n",t);
		for(i=0;i<=4*n-2;i++)
		{
			for(j=0;j<=4*n+2;j++)
				printf("%c",s[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}