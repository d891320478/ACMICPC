#include<cstdio>
#include <cstring>
#define N 1000010
int next[N],i,j,l;
char s[N];
int main()
{
	while (gets(s) && s[0]!='.')
	{
		j=next[0]=-1;
		l=strlen(s);
		for(i=1;s[i];i++)
		{
			while (j>-1 && s[j+1]!=s[i]) j=next[j];
			if(s[j+1]==s[i]) j++;
			next[i]=j;
		}
		printf("%d\n",(l%(l-next[l-1]-1) || next[l]==-1)?1:l/(l-next[l-1]-1));
	}
	return 0;
}