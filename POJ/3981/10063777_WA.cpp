#include <cstdio>
#include <cstring>

char s[1002],i,l;

int main ()
{
	while (gets(s)!=NULL)
	{
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(i+2<l)
			{
				if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
				{
					printf("we");
					i+=2;
				}
				else printf("%c",s[i]);
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}
	
	return 0;
}
