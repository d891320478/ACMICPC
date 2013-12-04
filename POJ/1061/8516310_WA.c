#include<stdio.h>

long int x,y,m,n,l;

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

long int modular(long int a,long int b,long int n)
{
    long int d,x,y;
    long int *xx=&x,*yy=&y;    
    
    d=exteuclid(a,n,xx,yy);
    if(b%d)return -1;
    x=x*(b/d);
    x=(x%(n/d)+n/d)%(n/d);
    return x;
}

int main()
{
    long int result;
    
    scanf("%ld%ld%ld%ld%ld",&x,&y,&m,&n,&l);
    if(n==m)printf("Impossible\n");
    result=modular(x-y,m-n,l);
    if(result==-1)printf("Impossible\n");
    else printf("%ld\n",result>0?result:-result);

    return 0;
}
