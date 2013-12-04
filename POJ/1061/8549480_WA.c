#include<stdio.h>

long long x,y,m,n,l,xx,yy,d;

long long exteuclid(long long a,long long b,long long *x,long long *y)
{
    long long d,tmp;
    
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
    scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
    if(n==m)
    {
    	  printf("Impossible\n");
    	  return 0;
    }
    d=exteuclid(n-m,l,&xx,&yy);
    if(! (x-y)%d)printf("Impossible\n");
    else
    {
        xx=xx*((x-y)/d);
        xx=(xx%(l/d)+(l/d))%(l/d);
        printf("%I64d\n",xx);
    }
    return 0;
}
