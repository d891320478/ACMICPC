double ptoline(point3 p,point3 l1,point3 l2)
{
	return length((p-l1)*(l2-l1))/dist3(l1,l2);
}
