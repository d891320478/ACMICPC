double dist_line(point3 u1,point3 v1,point3 u2,point3 v2)
{
	point3 n=(u1-v1)*(u2-v2);
	double len=length(n);
	if(sgn(len)==0) return ptoline(u1,u2,v2);
	return fabs((u1-u2)^n)/len;
}
