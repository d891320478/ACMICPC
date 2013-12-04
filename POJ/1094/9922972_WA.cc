#include <cstdio>
#include <cstring>

int n,m,p;
char ch;
int a[30][30];

int tp(int q)
{
	int r[30]={0},b[30]={0},u[30]={0};

	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(a[i][j])r[j]++;
	for(int i=1;i<=p;i++)
	{
		int j,c=0,k;

		for(j=1;j<=n;j++)
		if(! u[j])
		if(r[j]==0)
		{
			c++;
			k=j;
			u[j]=1;
		}
		if(c>1)return 0;
		if(c==0)
		{
			printf("Inconsistency found after %d relations.\n",q);
			return 1;
		}
		b[i]=k;
		for(j=1;j<=n;j++)
			if(a[k][j])r[j]--;
	}
	if(p<n)return 0;
	printf("Sorted sequence determined after %d relations: ",q);
	for(int i=1;i<=n;i++)
		printf("%c",'A'-1+b[i]);
	printf(".\n");
	return 1;
}

int main ()
{
	while(scanf("%d%d%c",&n,&m,&ch) && !(n==0 && m==0))
	{
		char s[1000][5];
		int u[30]={0},i;
		
		for(int i=1;i<=m;i++)
			scanf("%s",s[i]);
		memset(a,0,sizeof(a));
		p=0;
		for(i=1;i<=m;i++)
		{
			a[s[i][0]-'A'+1][s[i][2]-'A'+1]=1;
			if(! u[s[i][0]-'A'+1])
			{
				p++;
				u[s[i][0]-'A'+1]=1;
			}
			if(! u[s[i][2]-'A'+1])
			{
				p++;
				u[s[i][2]-'A'+1]=1;
			}
			if(tp(i))break;
		}
		if(i>m)printf("Sorted sequence cannot be determined.\n");
	}

	return 0;
}