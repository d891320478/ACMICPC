//计算四个平面围成的四面体体积
struct point3
{
    double x,y,z;
    void init(){scanf("%lf%lf%lf",&x,&y,&z);}
}c[5];
int lc;
struct line3{    point3 a,b;};
struct plane3{    point3 a,b,c;}p[5];
point3 xmult(point3 u,point3 v)//计算叉积 U x V
{
    point3 ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}
double dmult(point3 u,point3 v)//计算点积 U . V
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
point3 subt(point3 u,point3 v)//矢量差U - V
{
    point3 ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    ret.z=u.z-v.z;
    return ret;
}
double vlen(point3 p)//向量大小
{
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
point3 pvec(plane3 s)//取平面法向量
{
    return xmult(subt(s.a,s.b),subt(s.b,s.c));
}
int parallel(plane3 u,plane3 v)//判两平面平行
{
    return vlen(xmult(pvec(u),pvec(v)))<EPS;
}
int parallel(point3 a,point3 b,plane3 s)//判直线与平面平行
{
    return fabs(dmult(subt(a,b),pvec(s)))<EPS;
}
point3 intersection(point3 l1,point3 l2,plane3 s)//计算直线与平面交点
{
    point3 ret=pvec(s);
    point3 s1=s.a,s2=s.b,s3=s.c;
    double t=(ret.x*(s1.x-l1.x)+ret.y*(s1.y-l1.y)+ret.z*(s1.z-l1.z))/
    (ret.x*(l2.x-l1.x)+ret.y*(l2.y-l1.y)+ret.z*(l2.z-l1.z));
    ret.x=l1.x+(l2.x-l1.x)*t;
    ret.y=l1.y+(l2.y-l1.y)*t;
    ret.z=l1.z+(l2.z-l1.z)*t;
    return ret;
}
line3 intersect(plane3 u,plane3 v)//计算两平面交线
{
    line3 ret;
    ret.a=parallel(v.a,v.b,u)?intersection(v.b,v.c,u):intersection(v.a,v.b,u);
    ret.b=parallel(v.c,v.a,u)?intersection(v.b,v.c,u):intersection(v.c,v.a,u);
    return ret;
}
double volume(point3 a, point3 b, point3 c, point3 d)//四面体有向体积*6
{
    return dmult(xmult(subt(b,a),subt(c,a)),subt(d,a));
}
void solve(plane3 u,plane3 v,plane3 w)
{
    if(parallel(u,v)) return;
    line3 l=intersect(u,v);
    if(parallel(l.a,l.b,w)) return;
    c[++lc]=intersection(l.a,l.b,w);
}
int main ()
{
    int i,j;
    while (scanf("%lf%lf%lf",&p[1].a.x,&p[1].a.y,&p[1].a.z)!=-1)
    {
        p[1].b.init(); p[1].c.init();
        for(i=2;i<=4;i++)
        {
            p[i].a.init();
            p[i].b.init();
            p[i].c.init();
        }
        lc=0;
        solve(p[1],p[2],p[3]);
        solve(p[1],p[2],p[4]);
        solve(p[1],p[3],p[4]);
        solve(p[2],p[3],p[4]);
        if(lc<4) printf("0.00\n");
        else printf("%.2lf\n",fabs(volume(c[1],c[2],c[3],c[4])/6.0));
    }
    
    return 0;
}
