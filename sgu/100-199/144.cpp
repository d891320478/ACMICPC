#include <cstdio>
#define EPS 1e-12
double x,y,z;
int main ()
{
	scanf("%lf%lf%lf",&x,&y,&z);
	z/=60.0;
	printf("%.7lf\n",EPS+(z*z+2*z*(y-x-z))/(y-x)/(y-x));
	return 0;
}
