#include<stdio.h>

int main()
{
    double sum=0,avg,a;
    int i;
    
    for(i=1;i<=12;i++)
    {
        scanf("%lf",&a);
        sum+=a;
    }    
    avg=sum/12;
    printf("$%0.2lf\n",avg);
    
    return 0;
}
