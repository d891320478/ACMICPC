#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n;

int main ()
{
cin>>n;
	while(n)
	{
		int cou,ma=0,b;
		double a[1002][1002]={0};
		long s[1002][2]={0};
		
		for (unsigned int i = 0; i < n; i += 1)
			cin>>s[i][0]>>s[i][1];
		if(n==1 || n==0 || n==2)
		{
			cout<<n<<endl;
			continue;
		}
		for (unsigned int i = 0; i < n; i += 1)
		{
			b=0;
			for (unsigned int j = 0; j < n; j += 1)
				if(i!=j)
				{
					if(s[i][0]-s[j][0]==0)a[i][b++]=3.14159265358;
					else
					{
						a[i][b++]=(double)(s[j][1]-s[i][1])/(double)(s[j][0]-s[i][0]);
					}
				}
		}
		for (unsigned int i = 0; i < n; i += 1)
		{
			sort(a[i],a[i]+n-1);
		}
		/*for (unsigned int i = 0; i < n; i += 1)
		{
			for (unsigned int j = 0; j < n-1; j += 1)
			{
				cout<<a[i][j]<<"  ";
			}
			cout<<endl;
		}*/
		for (unsigned int i = 0; i < n; i += 1)
		{
			cou=2;
			for (unsigned int j = 0; j < n-2; j += 1)
			{
				if(a[i][j]==a[i][j+1])cou++;
				else cou=2;
				ma=ma>cou?ma:cou;
			}
		}
		cout<<ma<<endl;
cin>>n;
	}
	
	return 0;
}
