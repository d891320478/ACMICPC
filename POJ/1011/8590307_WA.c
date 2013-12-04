#include<stdio.h>
#include<string.h>

int n;
int a[65],sum;
int f[65];
int i,j,temp;
int b[2000],l;

int success(int cd)
{
	  int l;
	  int i,j;
	  
	  for(i=n;i>=1;i--)
	  {
	  	  if(f[i])continue;
	  	  f[i]=1;
	  	  l=a[i];
	  	  for(j=i-1;j>=1;j--)
	  	  {
	  	      if((l+a[j]<=cd) && (! f[j]))
	  	  	  {
	  	  	      l+=a[j];
	  	  	  	  f[j]=1;
	  	  	  }
	  	  	  if(l==cd)break;
	  	  }
	  	  if(l<cd)return 0;
	  }
	  return 1;
}

int main()
{
		scanf("%d",&n);
		while(n)
		{
			  sum=0;
		    for(i=1;i<=n;i++)
		    {
		    	  scanf("%d",&a[i]);
		    	  sum+=a[i];
		    }
		    for(i=1;i<n;i++)
		    for(j=n;j>i;j--)
		        if(a[j]<a[j-1])
		        {
		        	  temp=a[j];
		        	  a[j]=a[j-1];
		        	  a[j-1]=temp;
		        }
		    l=1;
		    for(i=a[n];i<=sum/2;i++)
		    	  if(! (sum%i))b[l++]=i;
		    b[l]=sum;
		    for(i=1;i<=l;i++)
		    {
		    	  memset(f,0,n);
		    	  if(success(b[i]))break;
		    }
		    printf("%d\n",b[i]);
		    scanf("%d",&n);
		}
		return 0;
}
