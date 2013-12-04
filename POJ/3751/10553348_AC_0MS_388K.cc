#include <cstdio>
int a,b,c,d,e,f,g,t;
int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d/%d/%d-%d:%d:%d",&a,&b,&c,&d,&e,&f);
		if(b<10)printf("0");printf("%d/",b);
		if(c<10)printf("0");printf("%d/%d-",c,a);
		g=d%12;
		if(g==0)g=12;
		if(g<10)printf("0");printf("%d:",g);
		if(e<10)printf("0");printf("%d:",e);
		if(f<10)printf("0");printf("%d",f);
		if(d>=12)printf("pm\n");
		else printf("am\n");
	}
	
	return 0;
}
