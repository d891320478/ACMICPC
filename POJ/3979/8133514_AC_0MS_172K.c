#include<stdio.h>
#include<math.h>

int gcd(int a,int b)
{
    if(b==0)return a;
    else return (b,gcd(b,a%b));
}

int main()
{
    int a,b,c,d,e,f,g,h;
    char s[8];
    
    while (scanf("%s",s)!=EOF)
    {
        a=s[0]-'0';
        b=s[2]-'0';
        c=s[4]-'0';
        d=s[6]-'0';
        f=b*d;
        if(s[3]=='+')e=a*d+c*b;
        else e=a*d-c*b;
        
        g=abs(e);
        h=gcd(f,g);
        g/=h;
        f/=h;
        if(e==0) printf("0\n");
        else if(e>0) {printf("%d",g);if(f!=1)printf("/%d\n",f);else printf("\n");}
             else if(e<0) {printf("-%d",g);if(f!=1)printf("/%d\n",f);else printf("\n");}
    }
    
    return 0;
}
