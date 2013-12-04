#include <cstdio>
const double inf=(double)1e20;
double n,a[1000010],b[1000010],c[1000010],ans=0;

void gb(long s,long t)
{
    long m=(s+t)/2;
    long i,j,k;

    if(s==t)return;
    gb(s,m); gb(m+1,t);
    for(i=1;i<=m-s+1;i++) b[i]=a[s+i-1];
    for(j=m+1;j<=t;j++) c[j-m]=a[j];
    i=j=1;
    b[m-s+2]=c[t-m+1]=inf;
    for(k=s;k<=t;k++)
    {
        if(b[i]<c[j]) a[k]=b[i++];
        else
        {
            a[k]=c[j++];
            ans+=m-s+2-i;
        }
    }
}

int main ()
{
    while(scanf("%lf",&n) && n)
    {
		for(int i=1;i<=n;i++)
		    scanf("%lf",&a[i]);
		ans=0;
		gb(1,(long)n);
		printf("%.0lf\n",ans);
	}
    
    return 0;
}