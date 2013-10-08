//过圆外一点求圆的切线
void TPC(point poi,point o,double r,point &r1,point &r2)  
{  
    double line=sqrt((poi.x-o.x)*(poi.x-o.x)+(poi.y-o.y)*(poi.y-o.y));  
    double angle=acos(r/line);  
    point unit,lin;  
    lin.x=poi.x-o.x;  
    lin.y=poi.y-o.y;  
    unit.x=lin.x/sqrt(lin.x*lin.x+lin.y*lin.y)*r;  
    unit.y=lin.y/sqrt(lin.x*lin.x+lin.y*lin.y)*r;  
    r1=rotate(unit,-angle);  
    r2=rotate(unit,angle);  
    r1.x+=o.x; r1.y+=o.y;  
    r2.x+=o.x; r2.y+=o.y;  
}
