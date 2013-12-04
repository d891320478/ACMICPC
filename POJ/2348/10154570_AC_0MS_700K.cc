#include <cstdio>
#include <iostream>
using namespace std;

int a,b;

int f(int a,int b)
{
	if(a<b)swap(a,b);
	if(a%b==0)return 1;
	if(a/b<2)return 1-f(b,a%b);
	if(a/b>=2)return 1;
}

int main ()
{
	while(scanf("%d%d",&a,&b))
	{
		if(a==0 && b==0)break;
		if(a==0 || b==0)
		{
			printf("Ollie wins\n");
			continue;
		}
		if(a<b)swap(a,b);
		if(a%b==0)
		{
			printf("Stan wins\n");
			continue;
		}
		if(f(a,b))printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	
	return 0;
}
