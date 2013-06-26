//多边形面积和重心
point p[NN],c;
int n;
double area;
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
		p[n+1]=p[1];
		area=c.x=c.y=0;
		for(int i=1;i<=n;i++)
		{
			double tmp=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
			area+=tmp;
			c.x+=(p[i].x+p[i+1].x)*tmp;
			c.y+=(p[i].y+p[i+1].y)*tmp;
		}
		c.x/=3.0*area; c.y/=3.0*area;
		printf("%.2lf %.2lf\n",c.x,c.y);
	}
	return 0;
}
