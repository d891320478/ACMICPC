#include <cstdio>

int main()
{
	char s[300];
	
	while (1)
	{
		gets(s);
		if(s[0]=='#')break;
		long sum=0;
		for(int i=0;s[i];i++)
		    if(s[i]!=' ')sum+=(i+1)*(s[i]-'A'+1);
		printf("%ld\n",sum);
	}
	
	return 0;
}