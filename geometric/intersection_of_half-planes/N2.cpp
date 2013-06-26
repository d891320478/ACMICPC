#define N 1510
#define EPS 1e-8
struct point
{	double x,y;	}inp[N],p[N],q[N];
int n;	double r;	int cnt,curcnt;
/*inline void getline(point p1,point p2,double &a,double &b,double &c)
{
	a=p2.y-p1.y;
	b=p1.x-p2.x;
	c=p2.x*p1.y-p1.x*p2.y;
}
inline point intersect(point p1,point p2,double a,double b,double c)
{
	double u=fabs(a*p1.x+b*p1.y+c);
	double v=fabs(a*p2.x+b*p2.y+c);
	point poi;
	poi.x=(p1.x*v+p2.x*u)/(u+v);
	poi.y=(p1.y*v+p2.y*u)/(u+v);
	return poi;
}
inline void cut(double a,double b,double c)
{
	int i;	curcnt=0;
	for(i=1;i<=cnt;i++)
		if(a*p[i].x+b*p[i].y+c> - EPS) q[++curcnt]=p[i];
		else
		{
			if(a*p[i-1].x+b*p[i-1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i-1],a,b,c);
			if(a*p[i+1].x+b*p[i+1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i+1],a,b,c);
		}
	for(i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1];		p[0]=p[curcnt];		cnt=curcnt;
}*/
double xmult(point p1,point p2,point p0)
{	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);	}
point intersect(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;	ret.y+=(u2.y-u1.y)*t;	return ret;
}
inline void cut(point p1,point p2)
{
	int i;	curcnt=0;
	for(i=1;i<=cnt;i++)
	{
		if(xmult(p[i],p2,p1)> - EPS) q[++curcnt]=p[i];
		else
		{
			if(xmult(p[i-1],p2,p1)>EPS) q[++curcnt]=intersect(p[i],p[i-1],p1,p2);
			if(xmult(p[i+1],p2,p1)>EPS) q[++curcnt]=intersect(p[i],p[i+1],p1,p2);
		}
	}
	for(i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1];	p[0]=p[curcnt];	cnt=curcnt;
}
inline void solve()//注意：默认点是顺时针，如果题目不是顺时针，规整化方向
{
	for(int i=1;i<=n;i++) cut(inp[i],inp[i+1]);
	/*for(int i=1;i<=n;i++)//向内推进R
	{
		point ta,tb,tt;  
        tt.x = inp[i+1].y - inp[i].y;      tt.y = inp[i].x - inp[i+1].x;  
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);  
        tt.x = tt.x * k;            tt.y = tt.y * k;  
        ta.x = inp[i].x + tt.x;      ta.y = inp[i].y + tt.y;  
        tb.x = inp[i+1].x + tt.x;    tb.y = inp[i+1].y + tt.y;
        cut(ta,tb);
	}*/
}
inline void gzh() //规整化方向，逆时针变顺时针，顺时针变逆时针
{	for(int i=1;i<(n+1)/2;i++)	 swap(inp[i],inp[n-i]);	inp[n+1]=inp[1];	}
double area(point *p,int n)//有向面积，顺时针为负，逆时针为正
{
	double s=0.0;
	for(int i=1;i<=n;i++)	s+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
	return s;
}
int main ()
{
	int tt,i;		scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lf%lf",&inp[i].x,&inp[i].y);
		inp[n+1]=inp[1];		if(area(inp,n)>0) gzh();
		for(int i=1;i<=n;i++) p[i]=inp[i];
		p[n+1]=p[1];	p[0]=p[n];	cnt=n;
		solve();		double ans=area(p,cnt)/2.0;	printf("%.2f\n",fabs(ans));
	}
	return 0;
}
