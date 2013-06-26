double xmult(point p0, point p1, point p2)
{	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);	}
bool intersect(point u1,point u2, point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x)) && (max(v1.x,v2.x)>=min(u1.x,u2.x))
		&& (max(u1.y,u2.y)>=min(v1.y,v2.y)) && (max(v1.y,v2.y)>=min(u1.y,u2.y))
		&& (xmult(u1,v1,u2)*xmult(u1,u2,v2)>0) && (xmult(v1,u1,v2)*xmult(v1,v2,u2)>0);
}
