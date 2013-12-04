#include<stdio.h>
#include <algorithm>
using namespace std;
 
long int n,s,i;
long int a[20002],l=0,sum=0;

int main()
{
    
    scanf("%ld%ld",&n,&s);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    sort(a,a+n);
    for(i=n-1;sum<s;i--)
    {
        sum+=a[i];
        l++;
    }
    printf("%ld\n",l);
    
	return 0;
}
