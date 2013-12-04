#include<cstdio>
#include<cstring>
#define N 30
int n;
int a[N][N][N],b[N][N][N];
int main()
{
	int fffff=0;
	while(scanf("%d",&n) && n)
	{
		if(! fffff)fffff=1;
		else printf("\n\n");
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)
		{
			int j=1,x;
			while(scanf("%d",&x) && x)
			{
				for(int k=1;k<=x;++k)
					a[i][j][k]=1;
				++j;
			}
		}
		memset(b,0,sizeof(b));
		for(int i=1;i<30;++i)
		for(int j=1;j<30;++j)
		for(int k=1;k<30;++k)
			b[k][i][j]=a[i][j][k];
		for(int i=1;;++i)
		{
			if(b[i][1][1]==0) break;
			int flag=0;
			for(int j=1;;++j)
			{
				if(b[i][j][1]==0) break;
				int k=1;
				while(b[i][j][k]) ++k;
				if(! flag) flag=1;
				else printf(" ");
				printf("%d",k-1);
			}
			printf("\n");
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<30;++i)
		for(int j=1;j<30;++j)
		for(int k=1;k<30;++k)
			a[k][i][j]=b[i][j][k];
		printf("\n");
		for(int i=1;;++i)
		{
			if(a[i][1][1]==0) break;
			int flag=0;
			for(int j=1;;++j)
			{
				if(a[i][j][1]==0) break;
				int k=1;
				while(a[i][j][k]) ++k;
				if(! flag) flag=1;
				else printf(" ");
				printf("%d",k-1);
			}
			printf("\n");
		}
	}
	return 0;
}