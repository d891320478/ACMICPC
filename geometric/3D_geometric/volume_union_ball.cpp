//两球体积并
#define PI acos(-1)
#define EPS 1e-6
struct circle{	double x,y,z,r;		}a,b;
double dist(circle a,circle b)
{	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0)+pow(a.z-b.z,2.0));	}
void work(circle a,circle b)
{
	double dis=dist(a,b),ans,mx,mn,h1,h2;
	if(a.r+b.r<dis || fabs(a.r+b.r-dis)<EPS)
	{
		ans=4.0/3.0*PI*pow(a.r,3.0)+4.0/3.0*PI*pow(b.r,3.0);
		printf("%.2lf\n",ans);		return;
	}
	mx=a.r>b.r?a.r:b.r;		mn=a.r<b.r?a.r:b.r;
	if(mn+dis<mx || fabs(mn+dis-mx)<EPS)
	{
		ans=4.0/3.0*PI*pow(mx,3.0);
		printf("%.2lf\n",ans);		return;
	}
	h1=((pow(a.r,2.0)-pow(b.r,2.0))/dis+dis)/2.0;
	h2=(dis-(pow(a.r,2.0)-pow(b.r,2.0))/dis)/2.0;
	ans=PI*(a.r*pow(a.r+h1,2.0)-1.0/3.0*pow(a.r+h1,3.0));
	ans+=PI*(b.r*pow(b.r+h2,2.0)-1.0/3.0*pow(b.r+h2,3.0));
	printf("%.2lf\n",ans);
}
int main ()
{
	int t;		scanf("%d",&t);
	while (t--)
	{
		scanf("%lf%lf%lf%lf",&a.x,&a.y,&a.z,&a.r);
		scanf("%lf%lf%lf%lf",&b.x,&b.y,&b.z,&b.r);
		work(a,b);
	}
	return 0;
}
