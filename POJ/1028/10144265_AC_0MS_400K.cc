#include <cstdio>
#include <cstring>

char s[1000][100]={"http://www.acm.org/"};
char ord[10],web[100];
int a=0,b=0;

int main()
{
	while(scanf("%s",ord))
	{
		if(strcmp(ord,"QUIT")==0)break;
		if(strcmp(ord,"VISIT")==0)
		{
			a++; b=a;
			scanf("%s",s[a]);
			printf("%s\n",s[a]);
		}
		if(strcmp(ord,"BACK")==0)
		{
			if(a>0)
			{
				a--;
				printf("%s\n",s[a]);
			}
			else printf("Ignored\n");
		}
		if(strcmp(ord,"FORWARD")==0)
		{
			if(a<b)
			{
				a++;
				printf("%s\n",s[a]);
			}
			else printf("Ignored\n");
		}
	}
	
	return 0;
}