//三角形外心
point center(point a,point b,point c)
{
	point u1,u2,v1,v2;
	u1.x=(a.x+b.x)/2.0;	u1.y=(a.y+b.y)/2.0;
	u2.x=u1.x+u1.y-a.y;	u2.y=u1.y-u1.x+a.x;
	v1.x=(a.x+c.x)/2.0;	v1.y=(a.y+c.y)/2.0;
	v2.x=v1.x+v1.y-a.y;	v2.y=v1.y-v1.x+a.x;
	return intersect(u1,u2,v1,v2);
}
point circumcenter(point a,point b,point c)  
{  
    point ret;  
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;   
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;   
    double d = a1 * b2 - a2 * b1;   
    ret.x = a.x + (c1*b2 - c2*b1)/d;   
    ret.y = a.y + (a1*c2 - a2*c1)/d;   
    return ret;  
} 
