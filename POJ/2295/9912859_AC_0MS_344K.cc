#include <cstdio>

int t;
char ch;

int main ()
{
	scanf("%d%c",&t,&ch);
	while(t--)
	{
		char s[300],s1[300],s2[300];
		long a=0,b=0,c=0,flag=1,i,j=0;
		
		scanf("%s",s);
		for(i=0;s[i]!='=';i++)
			s1[i]=s[i];
		s1[i]='+'; s1[i+1]='\0';
		i++;
		for(;s[i];i++)
			s2[j++]=s[i];
		s2[j]='+'; s2[j+1]='\0';
		for(i=0;s1[i];i++)
		{
			if(s1[i]>='0' && s1[i]<='9')c=c*10+(s1[i]-'0');
			else
			{
				if(s1[i]=='x')
				{
					if(i==0 || !(s1[i-1]>='0' && s1[i-1]<='9'))a+=flag;
					else a+=flag*c;
					i++;
				}
				else b+=flag*c;
				if(s1[i]=='+')flag=1;
				else flag=-1;
				c=0;
			}
		}
		flag=-1; c=0;
		for(i=0;s2[i];i++)
		{
			if(s2[i]>='0' && s2[i]<='9')c=c*10+(s2[i]-'0');
			else
			{
				if(s2[i]=='x')
				{
					if(i==0 || !(s2[i-1]>='0' && s2[i-1]<='9'))a+=flag;
					else a+=flag*c;
					i++;
				}
				else b+=flag*c;
				if(s2[i]=='-')flag=1;
				else flag=-1;
				c=0;
			}
		}
		if(a==0 && b!=0)printf("IMPOSSIBLE\n");
		else if(a==0 && b==0)printf("IDENTITY\n");
			else if(a*b>0 && b%a!=0)printf("%ld\n",-b/a-1);
				else printf("%ld\n",-b/a);
	}
	
	return 0;
}
