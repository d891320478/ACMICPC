#include <cstdio>
#include <cstring>

int n,l,f[5002][5002],i,j;
char ch,s[5002],t[5002];

int main ()
{
	scanf("%d%c",&n,&ch);
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++)
		t[i]=s[l-i-1];
	t[l]='\0';
	for(i=1;i<=l;i++)
	for(j=1;j<=l;j++)
	{
		if(s[i-1]==t[j-1])f[i][j]=f[i-1][j-1]+1;
		else f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
	}
	printf("%d\n",n-f[n][n]);
	
	return 0;
}
