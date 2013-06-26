#define N 50010
#define INF 1e20
#define EPS 1e-8
struct point{	double x,y;	}p[N],sta[N];
int n,top;
int d[N*2],bot,tot;
double xmult(point p0,point p1,point p2){	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);	}
int cmp(point a,point b){	if(a.y<b.y)return 1;	if(a.y>b.y)return 0;	if(a.x<b.x)return 1;	return 0;	}
void melkman(point *p,int n,point *sta,int &m)
{
	int i;		bot=n-1; tot=n; d[tot++]=0; d[tot++]=1;
	for(i=2;i<n;i++){	if(fabs(xmult(p[d[tot-2]],p[d[tot-1]],p[i]))>EPS) break;	d[tot-1]=i;	}
	d[bot--]=i; d[tot++]=i;	if(xmult(p[d[n]],p[d[n+1]],p[d[n+2]])<-EPS) swap(d[n],d[n+1]);
	for(++i;i<n;++i)
	{
		if(xmult(p[d[bot+1]],p[d[bot+2]],p[i])>EPS && xmult(p[d[tot-2]],p[d[tot-1]],p[i])>EPS) continue;
		while (xmult(p[d[tot-2]],p[d[tot-1]],p[i])<EPS) --tot; d[tot++]=i;
		while (xmult(p[d[bot+1]],p[d[bot+2]],p[i])<EPS) ++bot; d[bot--]=i;
	}
	for(i=bot+1;i<tot;i++) sta[i-bot-1]=p[d[i]];
	m=tot-bot-2;
}
int main ()
{
	while (scanf("%d",&n) && n!=-1)
	{	for(int i=0;i<n;i++)	scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);	melkman(p,n,sta,top);
	}
	return 0;
}
