#define offset 1e15
#define zero(x) (((x)>0?(x):-(x))<EPS)
double xmult(point p1,point p2,point p3)
{	return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);	}
int inside_polygon(point q,int n,point *p,int on_edge)//on_edge为点在边上时的返回值
{
	point q2;		int i=0,count;
	while (i<n)
		for(count=i=0,q2.x=rand()+offset,q2.y=rand()+offset;i<n;i++)
		{
			if(zero(xmult(q,p[i],p[(i+1)%n])) && (p[i].x-q.x)*(p[(i+1)%n].x-q.x)<EPS && (p[i].y-q.y)*(p[(i+1)%n].y-q.y)<EPS) return on_edge;
			else if(zero(xmult(q,q2,p[i]))) break;
			else if(xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-EPS && xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-EPS) count++;
		}
	return count & 1;//严格内部返回1，严格外部返回0
}
