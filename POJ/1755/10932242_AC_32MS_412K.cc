#include <cstdio>
#include <cmath>
#define N 110
#define EPS 1e-16
#define INF 1<<30
int n,cnt,curcnt;
struct point{  
    double x,y;  
}p[1505],q[1505];  
struct Node{  
    double u,v,w;  
    void init(){scanf("%lf%lf%lf",&u,&v,&w);}
}z[105]; 
/*inline point intersect(point p1,point p2,double a,double b,double c)
{
	double u=fabs(a*p1.x+b*p1.y+c);
	double v=fabs(a*p2.x+b*p2.y+c);
	point poi;
	poi.x=(p1.x*v+p2.x*u)/(u+v);
	poi.y=(p1.y*v+p2.y*u)/(u+v);
	return poi;
}*/
inline point intersect(point p1,point p2,double a,double b,double c)
{  
    double u=fabs(a*p1.x+b*p1.y+c);  
    double v=fabs(a*p2.x+b*p2.y+c);  
    point t;  
    t.x=(p1.x*v+p2.x*u)/(u+v);
    t.y=(p1.y*v+p2.y*u)/(u+v);  
    return t;  
} 
/*inline void cut(double a,double b,double c)
{
	int i;
	curcnt=0;
	for(i=1;i<=cnt;i++)
	{
		if(a*p[i].x+b*p[i].y+c>-EPS) q[++curcnt]=p[i];
		else
		{
			if(a*p[i-1].x+b*p[i-1].y+c>EPS) q[++curcnt]=intersect(p[i-1],p[i],a,b,c);
			if(a*p[i+1].x+b*p[i+1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i+1],a,b,c);
		}
	}
	for(i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1];
	p[0]=q[curcnt];
	cnt=curcnt;
}*/
void cut(double a,double b,double c){  
    int tmp=0;  
    for(int i=1;i<=cnt;i++){  
        if(a*p[i].x+b*p[i].y+c>-EPS) q[++tmp]=p[i];  
        else{  
            if(a*p[i-1].x+b*p[i-1].y+c>EPS)  
                q[++tmp]=intersect(p[i-1],p[i],a,b,c);  
            if(a*p[i+1].x+b*p[i+1].y+c>EPS)  
                q[++tmp]=intersect(p[i],p[i+1],a,b,c);  
        }  
    }  
    for(int i=1;i<=tmp;i++)  
        p[i]=q[i];  
    p[0]=p[tmp];p[tmp+1]=p[1];  
    cnt=tmp;  
}  
/*double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}*/
double xmult(point p0,point p1,point p2){  
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);  
}  
/*double areas()
{
	double sum=0;
	for(int i=2;i<cnt;i++)
		sum+=xmult(p[1],p[i],p[i+1]);
	return -sum/2.0;
}*/
double areas(){  
    double area=0;  
    for(int i=2;i<cnt;i++)  
        area+=xmult(p[1],p[i],p[i+1]);  
    return -area/2.0;  
} 
int main ()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++) z[i].init();
		for(int i=0;i<n;i++)
		{
			int j;
			p[1].x=0;p[1].y=0;  
			p[2].x=0;p[2].y=INF;  
			p[3].x=INF;p[3].y=INF;  
			p[4].x=INF;p[4].y=0;  
			p[0]=p[4];p[5]=p[1];  
			cnt=4;  
			for(j=0;j<n;j++)
			if(j!=i)
			{
				double a,b,c;  
				a=(z[i].u-z[j].u)/(z[i].u*z[j].u);  
				b=(z[i].v-z[j].v)/(z[i].v*z[j].v);  
				c=(z[i].w-z[j].w)/(z[i].w*z[j].w);  
				if(a==0&&b==0&&c<EPS) break; 
				cut(a,b,c);
				if(fabs(areas())<EPS) break;
			}
			if(j<n) printf("No\n");
			else printf("Yes\n");
		}
	}	
	return 0;
}