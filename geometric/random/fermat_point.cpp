//多边形费马点
struct point{	double x,y;	}p[110],st,a;
double step,dist,b;	bool flag;	int n,i;
double dis(point a,point b){	return sqrt(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0));	}
int main ()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)		scanf("%lf%lf",&p[i].x,&p[i].y);
	st=p[0]; 	step=100.0;	dist=0.0;
	for(i=0;i<n;i++)		dist+=dis(st,p[i]);
	while (step>0.2)
	{
		flag=1;
		while (flag)
		{
			flag=0;		a=(point){st.x+step,st.y};		b=0.0;
			for(i=0;i<n;i++)	b+=dis(a,p[i]);
			if(b<dist)	{	st=a;		dist=b;	flag=1;		}
			a=(point){st.x-step,st.y};		b=0.0;
			for(i=0;i<n;i++)	b+=dis(a,p[i]);
			if(b<dist)	{	st=a;		dist=b;	flag=1;		}
			a=(point){st.x,st.y+step};
			b=0.0;
			for(i=0;i<n;i++)	b+=dis(a,p[i]);
			if(b<dist)	{	st=a;		dist=b;	flag=1;		}
			a=(point){st.x,st.y-step};		b=0.0;
			for(i=0;i<n;i++)	b+=dis(a,p[i]);
			if(b<dist)	{	st=a;		dist=b;	flag=1;		}
		}
		step/=2.0;
	}
	printf("%d\n",(int)(dist+0.5));
	return 0;
}

