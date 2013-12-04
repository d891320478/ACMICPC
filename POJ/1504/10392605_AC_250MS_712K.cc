#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string s,r;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		cin>>s>>r;
		int a[100]={0},b[100]={0};
		a[0]=s.size();
		b[0]=r.size();
		for(int i=1;i<=a[0];i++)
			a[i]=s[i-1]-'0';
		for(int i=1;i<=b[0];i++)
			b[i]=r[i-1]-'0';
		a[0]=a[0]>b[0]?a[0]:b[0];
		for(int i=1;i<=a[0];i++)
		{
			a[i]+=b[i];
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
		if(a[a[0]+1]>0) a[0]++;
		int j=1;
		for(;j<a[0] && a[j]==0;j++);
		for(;j<=a[0];j++)
			printf("%d",a[j]);
		printf("\n");
	}
	
	return 0;
}