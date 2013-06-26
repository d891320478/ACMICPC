//卢卡斯定理（c(2*n,n)/(n+1)%10007）
long long m,n,xx,yy,ans;
long long f(long long a,long long b)
{
    long long t=1,y=a;
    while(b) {   if(b & 1)t=t*y%10007;        y=y*y%10007;   b>>=1;  }
    return t;
}
void exteuclid(long long a,long long b)
{
    long long tmp;
    if(b==0)    {        xx=1; yy=0; return;    }
    exteuclid(b,a%b);
    tmp=xx;    xx=yy;    yy=tmp-a/b*yy;
}
void fs(long long s,long long t)
{
    long long a,b,i;
    while(s && t && ans)
    {
        long long c=1,d=1;
        a=s%10007;     b=t%10007;     s/=10007;     t/=10007;
        for(i=a-b+1;i<=a;i++) {    c=c*i%10007;    d=d*(i-a+b)%10007;      }
        exteuclid(10007,d);
        ans=ans*c%10007*yy%10007;
        if(ans<0)ans+=10007;
    }
}
int main()
{
    while(scanf("%lld%lld",&m,&n)!=EOF)
    {
        if(n==3)	{   printf("1\n");    continue;    }
        n-=2;        ans=1;        fs(2*n,n);
        if(!ans)	{   printf("0\n");  continue;     }
        exteuclid(10007,(n+1)%10007);
        ans=ans*yy%10007;
        if(ans<0)ans+=10007;
        printf("%lld\n",f(ans,m));
    }
    return 0;
}
