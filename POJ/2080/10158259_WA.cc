#include <cstdio>
char s[][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,m,year,month,k;
int main ()
{
	while (scanf("%d",&n))
	{
		months[2]=28;
		if(n==-1)break;
		m=n%7;
		year=2000;
		while(1)
		{
			k=365;
			if(year%4==0 && year&100!=0 || year%400==0)k++;
			if(n<k)break;
			n-=k;
			year++;
		}
		if(year%4==0 && year&100!=0 || year%400==0)months[2]++;
		month=0;
		while(1)
		{
			month++;
			if(n>months[month])n-=months[month];
			else break;
		}
		printf("%d-%02d-%02d %s\n",year,month,n,s[m]);
	}
	
	return 0;
}