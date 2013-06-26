//最小圆覆盖
#define EPS (1e-12)
#define N 100010
struct point
{
	double x,y;
}p[N],cir;
double r;
int dbcmp(double n)
{
	return n<-EPS?-1:n>EPS;
}
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point intersect(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;	ret.y+=(u2.y-u1.y)*t;	return ret;
}
point center(point a,point b,point c)
{
	point u1,u2,v1,v2;
	u1.x=(a.x+b.x)/2.0;
	u1.y=(a.y+b.y)/2.0;
	u2.x=u1.x+u1.y-a.y;
	u2.y=u1.y-u1.x+a.x;
	v1.x=(a.x+c.x)/2.0;
	v1.y=(a.y+c.y)/2.0;
	v2.x=v1.x+v1.y-a.y;
	v2.y=v1.y-v1.x+a.x;
	return intersect(u1,u2,v1,v2);
}
void min_cir(point *p,int n)
{
	random_shuffle(p,p+n);
	cir=p[0]; r=0;
	for(int i=1;i<n;i++)
	{
		if(dbcmp(dist(p[i],cir)-r)<=0) continue;
		cir=p[i]; r=0;
		for(int j=0;j<i;j++)
		{
			if(dbcmp(dist(p[j],cir)-r)<=0) continue;
			cir.x=(p[i].x+p[j].x)/2.0;
			cir.y=(p[i].y+p[j].y)/2.0;
			r=dist(cir,p[j]);
			for(int k=0;k<j;k++)
			{
				if(dbcmp(dist(p[k],cir)-r)<=0) continue;
				cir=center(p[i],p[j],p[k]);
				r=dist(cir,p[k]);
			}
		}
	}
}
