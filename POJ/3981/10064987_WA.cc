#include <cstdio>
#include <cstring>
#include<iostream>
using namespace std;
char s[1010],i,l;

int main ()
{
	while (cin.getline(s,1010))
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
					continue;
				}
				else printf("%c",s[i]);
			}
			else printf("%c",s[i]);
		}
		printf("\n");
	}
	
	return 0;
}