#include<stdio.h>
#include <algorithm>
using namespace std;
 
long int s,ss,s0;
long int a[20001];
int n,i,j;
long int sum=0;

int se(long int t)
{
    int s=0,w=n-1,mid;
    
    while(s<w)
    {
        mid=(s+w)/2;
        //printf("s %d   w %d   mid %d\n",s,w,mid);
  		if(a[mid]<=t)s=mid+1;
  		else w=mid;
  	}
  	//printf("s %d   w %d   mid %d\n",s,w,mid);
  	
	return s;
}

int main()
{

    
    scanf("%d%ld",&n,&s);
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    sort(a,a+n);
    for(i=0;i<n && a[i]<=s/2;i++)
    {
        ss=s-a[i];
        j=se(ss);
        sum+=j-i-(a[j]>ss);
        //printf("%d\n",se(ss));
    }
    printf("%ld\n",sum);
    
	return 0;
}
