//已知3点坐标，求平面ax+by+cz+d=0; 
void get_panel(TPoint p1,TPoint p2,TPoint p3,double &a,double &b,double &c,double &d){
	a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
    b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
    c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
    d = ( 0-(a*p1.x+b*p1.y+c*p1.z) );
}
