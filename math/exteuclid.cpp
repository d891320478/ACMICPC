//扩展欧几里德
long long exteuclid(long long a,long long b)
{
    long long tmp,d;
    if(b==0) {   x=1;  y=0; return a;    }
    d=exteuclid(b,a%b);
    tmp=x;    x=y;    y=tmp-a/b*y;
    return d;
}
//求逆元（a/b%c）
exteuclid(c,b,&x,&y);	a*y%c;
