#include <cstdio>
#include <cmath>

int t,n,o,p,a,b;
double mi,f,c,d;

int main()
{
    while(scanf("%lf%d",&f,&n)!=EOF)
    {
        mi=9999999999.0;
        a=b=1;
        while(a<=n && b<=n)
        {
            c=(double)a/(double)b;
            d=f-c;
            if(fabs(d)<mi)
            {
                o=a;
                p=b;
                mi=fabs(d);
            }
            if(d>0)a++;
            else b++;
        }
        printf("%d %d\n",o,p);
    }
    
    return 0;
}
