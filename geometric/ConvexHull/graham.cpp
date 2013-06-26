#define N 50010
#define INF 1e20
#define EPS 1e-8
struct point{	double x,y;	}p[N],sta[N];
int n,top;
double xmult(point p0,point p1,point p2){	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);	}
double dist(point a,point b){	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);	}
int cmp(point a,point b)
{	double xt=xmult(p[0],a,b);
	if(xt>EPS) return 1;	if(xt<-EPS) return 0;
	if(dist(p[0],a)<dist(p[0],b)) return 1;	return 0;
}
void graham(point *p,int n,point *sta,int &top)
{
	sta[0]=p[0]; sta[1]=p[1]; top=2;
	for(int i=2;i<n;i++)
	{	while (top>1 && xmult(sta[top-2],sta[top-1],p[i])<EPS) top--;	sta[top++]=p[i];	}
	sta[top]=sta[0];
}
int main ()
{
	while (scanf("%d",&n)!=-1)
	{	double mx=INF,my=INF; int k;
		for(int i=0;i<n;i++)
		{	scanf("%lf%lf",&p[i].x,&p[i].y);
			if(p[i].x<mx){	k=i;	mx=p[i].x;	my=p[i].y;}
　　else if(p[i].x==mx && p[i].y<my)	{	k=i;	my=p[i].y;	}
		}
		swap(p[0],p[k]);	sort(p+1,p+n,cmp);		graham(p,n,sta,top);
	}
	return 0;
}
