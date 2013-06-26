//凸包最远点对
double xmult(point p0,point p1,point p2)
{	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);	}
void rotate(point *p,int n)
{	int x=1,i;		double t1,t2,ans=0.0,dif;
	for(i=0;i<n;i++)
	{
		while (fabs(xmult(p[x+1],p[i],p[i+1]))>fabs(xmult(p[x],p[i],p[i+1]))) x=(x+1)%n;
		dif=fabs(xmult(p[x+1],p[i],p[i+1]))-fabs(xmult(p[x],p[i],p[i+1]));
		if(fabs(dif)<EPS)
		{	t1=dist(p[x],p[i]);	t2=dist(p[x+1],p[i+1]);
			if(t1>ans) ans=t1;	if(t2>ans) ans=t2;
		} else if(dif<-EPS)
		{	t1=dist(p[x],p[i]);	if(t1>ans) ans=t1;	}
	}
	printf("%.0f\n",ans);
}
