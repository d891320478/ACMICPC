#include<stdio.h>

int main()
{
    int i;
    double sum,auv;
    
    scanf("%lf",&auv);
    while(auv!=0.00)
    {
        i=2;
        sum=0.50;
        while(sum<=auv)
        {
            sum+=1/(double)(++i);
        }
        printf("%d card(s)\n",i-1);
        scanf("%lf",&auv);
    }    
    
    return 0;
}
