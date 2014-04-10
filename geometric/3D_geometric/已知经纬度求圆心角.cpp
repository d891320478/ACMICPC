//lng经度[-180,180],lat纬度[-90,90]
double angle(double lng1,double lat1,double lng2,double lat2)
{
	double dlng=fabs(lng1-lng2)*PI/180;
	while(dlng-PI-PI>-EPS) dlng-=PI+PI;
	if(fabs(dlng)<EPS) dlng=0;
	if(dlng-PI>EPS) dlng=PI+PI-dlng;
	lat1*=PI/180;
	lat2*=PI/180;
	return acos(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2));
}
