#include <cstdio>
#include <cstring>

char s[110];
int a[110],b[110],i,l,la;

int main ()
{
	scanf("%s",s);
	la=strlen(s);
	for(i=0;i<la;i++)
		a[i]=s[la-i-1]-'0';
	while(strcmp(s,"0"))
	{
		scanf("%s",s);
		l=strlen(s);
		memset(b,0,sizeof(b));
		for(i=0;i<l;i++)
			b[i]=s[l-i-1]-'0';
		la=la<l?l:la;
		for(i=0;i<la;i++)
		{
			a[i]+=b[i];
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
		if(a[la-1]>=10)
		{
			a[la]=a[la-1]/10;
			a[la-1]%=10;
			la++;
		}
	}
	i=la-1;
	while(! a[i] && i>0)i--;
	for(;i>=0;i--)
		printf("%d",a[i]);
	printf("\n");
	
	return 0;
}