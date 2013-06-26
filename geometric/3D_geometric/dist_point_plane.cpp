//点到平面距离 
double dis_pt2panel(TPoint pt,double a,double b,double c,double d){
	return f_abs(a*pt.x+b*pt.y+c*pt.z+d)/sqrt(a*a+b*b+c*c);
}
