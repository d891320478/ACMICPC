#include<stdio.h>

long int x,y,m,n,l,a,b;
long int k;

int main()
{
    scanf("%ld%ld%ld%ld%ld",&x,&y,&m,&n,&l);
    a=y-x;
    b=m-n;
    k=(a/b%l+l)%l;
    printf("%ld\n",k);
    
    return 0;
}
