//平面旋转（ax+by+cz=d）
inline int sign(double d)
{	if(d>EPS) return 1;	if(d<-EPS) return -1;	return 0;	}
struct point
{
	double x,y,z;
	point(double x=0,double y=0,double z=0): x(x),y(y),z(z) {}
	point operator - (point p){	return point(x-p.x,y-p.y,z-p.z);	}
	point operator + (point p){	return point(x+p.x,y+p.y,z+p.z);	}
	point operator / (double len){	return point(x/len,y/len,z/len);}
	point operator * (double len){	return point(x*len,y*len,z*len);}
	double operator ^ (point p)	{	return x*p.x+y*p.y+z*p.z;	}//点积
	point operator * (point p){
		return point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
	}//叉积
	double getlen(){	return sqrt(x*x+y*y+z*z);	}//长度
}con[N],ps[N],org;
double a,b,c,d;	int n;
inline point get_point(point u,point v,point p)//p在uv上的垂足
{	double a,b,t;
	a=(v.x-u.x)*(v.x-u.x)+(v.y-u.y)*(v.y-u.y)+(v.z-u.z)*(v.z-u.z);
	b=(p.x-u.x)*(v.x-u.x)+(p.y-u.y)*(v.y-u.y)+(p.z-u.z)*(v.z-u.z);
	t=b/a;	point ans;
	ans.x=v.x*t+(1-t)*u.x;
	ans.y=v.y*t+(1-t)*u.y;
	ans.z=v.z*t+(1-t)*u.z;
	return ans;
}
inline double dist(point a,point b)
{ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)); }
point rotate(point u,point v,point p,double ang)//点p沿uv右旋ang角度
{
	point root=get_point(u,v,p),e,r; point ans;
	e=(v-u)/dist(u,v);	r=p-root;	e=e*r;
	ans=r*cos(ang)+e*sin(ang)+root;
	return ans;
}
double solve()
{
	point tp(0,0,0),end(0,0,1),vec;
	double ang;	int i,cn;
	if(sign(a)) tp.x=d/a;
	else if(sign(b)) tp.y=d/b;
	else if(sign(c)) tp.z=d/c;
	ps[n+1]=tp;	vec=(point(a,b,c))*(end);
	if(sign(vec.x)==0) vec.x=0;
	if(sign(vec.y)==0) vec.y=0;
	if(sign(vec.z)==0) vec.z=0;
	ang=(a*end.x+b*end.y+c*end.z)/(point(a,b,c).getlen());
	ang=acos(ang);
	if(sign(ang)!=-0 && sign(ang-PI)!=0)
	for(i=0;i<n;i++) ps[i]=rotate(org,vec,ps[i],ang);
	for(int i=0;i<n;i++) ps[i].z=0;
	//然后求凸包面积
	return ans;
}
