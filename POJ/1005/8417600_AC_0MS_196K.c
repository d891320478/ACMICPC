#include<stdio.h>
#include<math.h>

int n,i;
double x,y;

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&x,&y);
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,(int)((x*x+y*y)*3.14159265/100.0+1));
    }
    printf("END OF OUTPUT.\n");
    
    system("pause");
    return 0;
}
