#include <cstdio>

int i,j,f[1000][1000];
char s1[1001],s2[1001];

int main ()
{
	while (scanf("%s%s",s1,s2)!=EOF)
	{
		f[0][0]=0;
		for(i=1;s1[i-1];i++)
		for(j=1;s2[j-1];j++)
		{
			if(s1[i-1]==s2[j-1])f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
		}
		printf("%d\n",f[i-1][j-1]);
	}
	
	return 0;
}
