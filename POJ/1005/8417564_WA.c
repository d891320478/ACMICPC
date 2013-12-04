#include<stdio.h>
#include<math.h>

int year,n,i,j;
struct
{
    double x,y;
    double rr;
    int p;
}a[1001];
double pi=3.141592653;
double s=0.0,r=0.0;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
        a[i].rr=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
    }
    for(year=1,i=1;i<=n;year++)
    {
        s+=50.0;
        r=sqrt(s*2/pi);
        if(a[i].rr<r) a[i++].p=year;
    }
    for(i=1;i<=n;i++)
        printf("Property %d: This property will begin eroding in year %d.\n",i,a[i].p);
    printf("END OF OUTPUT.\n");

    return 0;
}
