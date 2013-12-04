#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long m,n,t,e;
double d=(sqrt(5.0)+1)/2;

int main ()
{
	while(scanf("%ld%ld",&m,&n)!=EOF)
	{
		if(m>n)swap(m,n);
		t=n-m;
		e=(long)(d*t);
		if(e==m)printf("0\n");
		else printf("1\n");
	}
	
	return 0;
}