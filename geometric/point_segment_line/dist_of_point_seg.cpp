point ptoseg(point p,point u1,point u2)
{
	point t=p;
	t.x+=u1.y-u2.y;
	t.y+=u2.x-u1.x;
	if(xmult(u1,t,p)*xmult(u2,t,p)>EPS) return dist(p,u1)<dist(p,u2)?u1:u2;
	return intersection(p,t,u1,u2);
}
