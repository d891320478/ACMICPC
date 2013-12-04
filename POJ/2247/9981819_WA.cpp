#include <cstdio>
#include <cstring>

int main ()
{
	long i=0,a[6000]={1},n,b1=0,b2=0,b3=0,b4=0;
	while(i<5842)
	{
		long min=2147483647;	
		if(min>a[b1]*2)min=a[b1]*2;
		if(min>a[b2]*3)min=a[b2]*3;
		if(min>a[b3]*5)min=a[b3]*5;
		if(min>a[b4]*7)min=a[b4]*7;
		a[++i]=min;
		if(min==a[b1]*2)b1++;
		if(min==a[b2]*3)b2++;
		if(min==a[b3]*5)b3++;
		if(min==a[b4]*7)b4++;
	}
	while(scanf("%ld",&n) && n)
	{
		char s[5];
		if(n>=10 && n<=20) strcpy(s,"th");
		else if(n%10==1) strcpy(s,"st");
			else if(n%10==2) strcpy(s,"nd");
				else if(n%10==3) strcpy(s,"rd");
					else strcpy(s,"th");
		printf("The %ld%s humble number is %ld.\n",n,s,a[n-1]);
	}
	
	return 0;
}
