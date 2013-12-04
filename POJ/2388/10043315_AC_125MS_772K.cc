#include <iostream>
#include <algorithm>
using namespace std;

long n,a[10001],i;

int main ()
{
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[n/2]<<endl;
	
	return 0;
}
