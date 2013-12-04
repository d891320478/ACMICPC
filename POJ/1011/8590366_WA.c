#include<stdio.h>
#include<string.h>

int n;
int a[65],sum;
int f[65];
int max;
int i;

int main()
{
		scanf("%d",&n);
		while(n)
		{
			  sum=0;
			  max=0;
		    for(i=1;i<=n;i++)
		    {
		    	  scanf("%d",&a[i]);
		    	  sum+=a[i];
		    	  max=max>a[i]?max:a[i];
		    }
		    for(i=max;i<=sum/2;i++)
		    	  if(! (sum%i)) { printf("%d\n",i); break; }
		    scanf("%d",&n);
		}
		return 0;
}
