//四面体体积【已知六边长】
//将a=OA，b=OB，c=OC,l=AB,m=BC,n=CA 带入下式计算，利用三个棱长求体积有个
　　v=sqrt(4*a*a*b*b*c*c
　　		-a*a*pow(b*b+c*c-m*m,2.0)
　　		-b*b*pow(c*c+a*a-n*n,2.0)
　　		-c*c*pow(a*a+b*b-l*l,2.0)
　　		+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n))/12;
//六边分别为 AB, AC, AD, BC, BD, CD.
　　while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&l,&m,&n)!=-1)
　　{
　　	t1=acos((b*b+c*c-n*n)/(2*b*c));
　　	t2=acos((a*a+c*c-m*m)/(2*a*c));
　　	t3=acos((a*a+b*b-l*l)/(2*a*b));
　　	t=(t1+t2+t3)/2;
　　	v=1.0/3.0*a*b*c*sqrt(sin(t)*sin(t-t1)*sin(t-t2)*sin(t-t3));
　　	printf("%f\n",v);
　　}
