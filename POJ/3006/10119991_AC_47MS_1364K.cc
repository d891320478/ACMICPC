#include <cstdio>
#include <algorithm>
using namespace std;

bool f[1000001]={1,1,0};
int i,j,a,b,n;

int main ()
{
	for(i=2;i<=1000000/2;i++) f[i*2]=1;
	for(i=3;i<=1000000;i+=2)
		if(! f[i])
		{
			for(j=3;j*i<=1000000;j++)
				f[i*j]=1;
		}
	while (scanf("%d%d%d",&a,&b,&n))
	{
		if(a==0 && b==0 && n==0)break;
		a-=b;
		while(n)
		{
			a+=b;
			if(! f[a])n--;
		}
		printf("%d\n",a);
	}
	
	return 0;
}