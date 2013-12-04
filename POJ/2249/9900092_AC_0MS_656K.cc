#include <iostream>
using namespace std;

int main ()
{
	int m,n;
	long long x;
	
	while (cin>>m>>n)
	{
		if(m==0 && n==0)break;
		if(n>m-n)n=m-n;
		x=1;
		for(int i=1;i<=n;i++)
			x=x*(i+m-n)/i;
		cout<<x<<endl;
	}
	
	return 0;
}