#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
#define EPS 1e-16
double b1,t1,b2,t2,l0,ds,df,g;
double _v(double h,double a,double b)
{
	return (a*b*g/2.0/h+g*h*(a+b)*(a+b)/2.0/a/b);
}
double _g(double a,double b,double hl,double hh)
{
	double h=a*b/(a+b);
	if(hl-h<EPS && h-hh<EPS) return g*(a+b);
	if(h-hl<EPS) return _v(hl,a,b);
	return _v(hh,a,b);
}
double _f(double x)
{
	double a1=_g(ds,x-ds,b1,t1);
	double a2=_g(l0+ds-x,df,b2,t2);
	return a1-a2>EPS?a1:a2;
}
int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&b1,&t1,&b2,&t2,&l0,&ds,&df,&g)!=-1)
	{
		double l=ds,r=ds+l0,m1,m2;
		for(int i=1;i<=500;++i)
		{
			m1=(r-l)/3.0+l;
			m2=(r-l)/3.0*2.0+l;
			if(_f(m1)-_f(m2)>EPS) l=m1;
			else r=m2;
		}
		printf("%lf\n",sqrt(_f((l+r)/2.0)));
	}
	return 0;
}
