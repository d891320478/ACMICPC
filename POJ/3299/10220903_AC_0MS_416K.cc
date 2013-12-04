#include <cstdio>
#include <cmath>
double a,b;
char c1,c2,ch;
void f1(double a,double b)
{
	double e = 6.11*exp(5417.7530*(1/273.16-1/(b+273.16)) );
	double h = 0.5555*(e-10.0);
	double hu = a+h;
	printf("T %.1f D %.1f H %.1f\n",a,b,hu);
}
void f2(double a,double b)
{
	double h=a-b;
	double e=h/0.5555+10.0;
	double d=1/(1/273.16-log(e/6.11)/5417.7530)-273.16;
	printf("T %.1f D %.1f H %.1f\n",b,d,a);
}
void f3(double a,double b)
{
	double e = 6.11*exp(5417.7530*(1/273.16-1/(a+273.16)) );
	double h = 0.5555*(e-10.0);
	double t = b-h;
	printf("T %.1f D %.1f H %.1f\n",t,a,b);
}
int main ()
{
	while (scanf("%c",&c1) && c1!='E')
	{
		scanf("%lf %c %lf%c",&a,&c2,&b,&ch);
		if(c1=='T' && c2=='D') f1(a,b);
		else if(c1=='D' && c2=='T') f1(b,a);
		else if(c1=='H' && c2=='T') f2(a,b);
		else if(c1=='T' && c2=='H') f2(b,a);
		else if(c1=='D' && c2=='H') f3(a,b);
		else if(c1=='H' && c2=='D') f3(b,a);
	}
	
	return 0;
}
