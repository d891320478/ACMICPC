double linetoline(point3 u1,point3 u2,point3 v1,point3 v2,point3 &a1,point3 &a2)
{
	point3 p1=u2-u1;
	point3 p2=v2-v1;
	point3 p=p1*p2;
	double dd=fabs(p^(u1-v1))/p.vlen();
	double t1=((v1-u1)*p2)^p,t2=((v1-u1)*p1)^p;
	t1/=p.vlen()*p.vlen();
	t2/=p.vlen()*p.vlen();
	a1=u1+p1*t1;
	a2=v1+p2*t2;
	return dd;
}
