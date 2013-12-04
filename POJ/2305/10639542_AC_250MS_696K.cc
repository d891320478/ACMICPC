#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define SET(a,b) memset(a,b,sizeof(a))
int n,m,a,b,d[2000],x,w,tmp;
string s;
int main ()
{
	while (scanf("%d",&n) && n)
	{
		cin>>s>>m;
		x=0,w=1;
		while (m)
		{
			x+=w*(m%10);
			m/=10;
			w*=n;
		}
		SET(d,0);
		a=1;
		tmp=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			b=a*(s[i]-'0')%x;
			tmp=(tmp+b)%x;
			a=a*n%x;
		}
		if(! tmp)
		{
			printf("0\n");
			continue;
		}
		while (tmp)
		{
			d[++d[0]]=tmp%n;
			tmp/=n;
		}
		for(int i=d[0];i>0;i--)
			printf("%d",d[i]);
		printf("\n");
	}
	
	return 0;
}