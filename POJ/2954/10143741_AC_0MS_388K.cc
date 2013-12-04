#include <cstdio>
#include <cstdlib>

int x1,x2,x3,y1,y2,y3;

int gcd(int a,int b)
{
	if(b)return gcd(b,a%b);
	else return a;
}

int main()
{
	while(1)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if(x1==0 && x2==0 && x3==0 && y1==0 && y2==0 && y3==0)break;
		int n=abs(x1*y2+x2*y3+x3*y1-y2*x3-y1*x2-x1*y3);
		int m=gcd(abs(x1-x2),abs(y1-y2))+gcd(abs(x2-x3),abs(y2-y3))+gcd(abs(x1-x3),abs(y1-y3));
		printf("%d\n",n/2+1-m/2);
	}
	
	return 0;
}