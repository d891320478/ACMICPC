//两圆面积交
double dist(point c1,point c2)
{
	return sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
}
double area_of_overlap(point c1,double r1,point c2,double r2)
{
	double a=dist(c1,c2),b=r1,c=r2;
	double cta1=acos((a*a+b*b-c*c)/2.0/(a*b));
	double cta2=acos((a*a+c*c-b*b)/2.0/(a*c));
	double s1=r1*r1*cta1-r1*r1*sin(cta1)*(a*a+b*b-c*c)/2.0/(a*b);
	double s2=r2*r2*cta2-r2*r2*sin(cta2)*(a*a+c*c-b*b)/2.0/(a*c);
	return s1+s2;
}
int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf",&c1.x,&c1.y,&r1,&c2.x,&c2.y,&r2)!=-1)
	{
		if(dist(c1,c2)+min(r1,r2)-max(r1,r2)<EPS) printf("%.3lf\n",PI*min(r1,r2)*min(r1,r2));
		else if((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)-(r1+r2)*(r1+r2)>-EPS) printf("0.000\n");
		else printf("%.3lf\n",area_of_overlap(c1,r1,c2,r2));
	}
	return 0;
}
