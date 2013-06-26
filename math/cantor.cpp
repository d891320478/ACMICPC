//康托展开
long z[10] = {1,1,2,6,24,120,720,5040,40320,362880};
void cantor(int s[],int n)
{
	int i,j,temp;	num=1;
	for(i=0;i<n-1;i++)
	{		temp=0;		for(j=i+1;j<n;j++)	if(s[j]<s[i]) temp++;
		num+=z[n-1-i]*temp;
	}
}
