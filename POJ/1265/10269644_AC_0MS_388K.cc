#include <cstdio>
int sum1,sum2,s,c,d,e,f,n;
struct point
{
	int x,y;
}a,b;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	int t,tt;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%d\n",&n);
		a=(point){0,0};
		s=sum1=sum2=0;
		while (n--)
		{
			scanf("%d%d",&c,&d);
			b=(point){a.x+c,a.y+d};
			e=b.x-a.x; f=b.y-a.y;
			if(e<0)e=-e; if(f<0)f=-f;
			if(f==0)sum1+=e;
			else if(e==0)sum1+=f;
			else sum1+=gcd(e,f);
			s+=a.x*b.y-b.x*a.y;
			a=b;
		}
		if(s<0)s=-s;
		sum2=(s-sum1+2)/2;
		if(tt>1)printf("\n");
		printf("Scenario #%d:\n",tt);
		printf("%d %d %d",sum2,sum1,s/2);
		if(s%2)printf(".5\n");
		else printf(".0\n");
	}
	
	return 0;
}
