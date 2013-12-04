#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
double m,n;
int main()
{
	while (cin>>m>>n)
	{
		printf("%.0f\n",exp(log(n)/m));
	}
	
	return 0;
}