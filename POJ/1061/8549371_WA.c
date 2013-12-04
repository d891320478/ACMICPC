#include<stdio.h>

long int x,y,m,n,l,xx,yy;

long int exteuclid(long int a,long int b,long int *x,long int *y)
{
    long int d,tmp;
    
    if(b==0)
    {
        *x=1;  *y=0;  return a;
    }
    d=exteuclid(b,a%b,x,y);
    tmp=*x;
    *x=*y;
    *y=tmp-a/b*(*y);
    return d;
}

int main()
{
    long int d;
    
    scanf("%ld%ld%ld%ld%ld",&x,&y,&m,&n,&l);
    if(n==m)
    {
    	  printf("Impossible\n");
    	  return 0;
    }
    d=exteuclid(n-m,l,&xx,&yy);
    if(! (x-y)%d)printf("Impossible\n");
    else printf("%ld\n",((xx*((x-y)/d))%(l/d)+l/d)%(l/d));

    return 0;
}
