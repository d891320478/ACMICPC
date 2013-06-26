//两个简单多边形面积并
#define N 510
#define EPS 1e-9
int sgn(double x){ return (x>EPS)-(x<-EPS); }//判断大于等于小于0
struct point
{
    double x, y;
    point() {};
    point(double xx, double yy):x(xx), y(yy) {}
    point operator - (point a){ return point(x-a.x, y-a.y); }
    void init(){ scanf("%lf%lf",&x,&y); }
}O(0,0);
inline double cross(point a,point b){ return a.x*b.y-a.y*b.x; }
inline double xmult(point p1, point p2, point p0)
{ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
inline double polygon_area(point p[],int n)
{
    double ans=0;
    for(int i=0;i<n;i++)ans+=xmult(p[i],p[(i+1)%n],O);
    return fabs(ans/2);
}
bool linelinecross(point p1,point p2,point p3,point p4,point &tmp)
{
    double a1,b1,c1,a2,b2,c2;
    a1=p1.y-p2.y; b1=p2.x-p1.x; c1=p2.y*p1.x-p1.y*p2.x;
    a2=p3.y-p4.y; b2=p4.x-p3.x; c2=p4.y*p3.x-p3.y*p4.x;
    if(sgn(a1*b2-b1*a2)==0)return 0;
    tmp=point((b1*c2-b2*c1)/(a1*b2-b1*a2),(a1*c2-a2*c1)/(a2*b1-b2*a1));
    return 1;
}
point intersect(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;	ret.y+=(u2.y-u1.y)*t;	return ret;
}
inline double convex_poly_inter_area(point A[],int an,point B[],int bn)//凸多边形面积并
{
    point tmp[N], tpp;
    int tn, i, j, next, now;
    A[an]=A[0]; B[bn]=B[0];
    for(i=0;i<an && bn>2; i++)
    {
        now=sgn(cross(A[i+1]-A[i], B[0]-A[i+1]));
        for(j=tn=0; j<bn; j++, now=next)
        {
            if(now>=0)tmp[tn++]=B[j];
            next=sgn(cross(A[i+1]-A[i], B[j+1]-A[i+1]));
            if(now*next<0) tmp[tn++]=intersect(A[i], A[i+1], B[j], B[j+1]);//tpp;
        }
        for(j=0; j<tn; j++)B[j]=tmp[j];
        bn=tn; B[bn]=B[0];
    }
    if(bn<3)return 0.00;
    return polygon_area(B, bn);
}
inline double simple_polygon_inter_area(point A[], int an, point B[], int bn)//简单多边形面积交
{
    point tp1[10], tp2[10];
    int tn1, tn2;
    double ans=0.00, flag1, flag2;
    for(int i=0; i<an; i++)
    {
        tp1[1]=A[i]; tp1[2]=A[(i+1)%an]; flag1=1.00;
        if(sgn(cross(tp1[1]-tp1[0], tp1[2]-tp1[1]))<0)flag1=-1.00, swap(tp1[1], tp1[2]);
        for(int j=0; j<bn; j++)
        {
            tp2[1]=B[j]; tp2[2]=B[(j+1)%bn]; flag2=flag1;
            if(sgn(cross(tp2[1]-tp2[0], tp2[2]-tp2[1]))<0)flag2*=-1.00, swap(tp2[1], tp2[2]);
            ans+=flag2*convex_poly_inter_area(tp1, 3, tp2, 3);
        }
    }
    return ans;
}
int main()
{
    point A[N], B[N];    int an, bn, i;
    while(~scanf("%d%d", &an, &bn))
    {
        for(i=0; i<an; i++)A[i].init();
        for(i=0; i<bn; i++)B[i].init();
        printf("%.2lf\n",polygon_area(A,an)+polygon_area(B, n)-simple_polygon_inter_area(A, an,B,bn));
    }
    return 0;
}

