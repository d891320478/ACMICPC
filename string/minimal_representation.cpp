int MNCD(char *s,int ls)//最小起始点
{
	int i=0,j=1,k=0,t;
	while (i<ls && j<ls && k<ls)
	{
		t=s[(i+k)%ls]-s[(j+k)%ls];
		if(t==0) ++k;
		else
		{
			if(t>0) i+=k+1;
			else j+=k+1;
			k=0;
			if(i>=j) j=i+1;
		}
	}
	return min(i,j);
}
int MXCD(char *s,int ls)//最大起始点
{
	int i=0,j=1,k=0,t;
	while (i<ls && j<ls && k<ls)
	{
		t=s[(i+k)%ls]-s[(j+k)%ls];
		if(t==0) ++k;
		else
		{
			if(t<0) i+=k+1;
			else j+=k+1;
			k=0;
			if(i>=j) j=i+1;
		}
	}
	return min(i,j);
}
bool CircularMatch(string s1, string s2, int len, int& pos1, int& pos2)//循环串同构判断
{
    int p1 = 0, p2 = 0, k, t1, t2;
    pos1 = pos2 = -1; 
    while (1) {
        k = 0;
        while (1) {
            t1 = (p1+k)%len; t2 = (p2+k)%len; 
            if(s1[t1] > s2[t2]) {
                p1 = p1+k+1;                
                if (p1 >= len) return false; 
                break; 
            }    
            else if (s1[t1] < s2[t2]) {
                p2 = p2+k+1;                
                if (p2 >= len) return false;  
                break; 
            }     
            else k++;
            if (k == len) { 
                pos1 = p1; pos2 = p2; 
                return true; 
            }    
        }     
    }     
}
int main(){
	string s1,s2;
	int pos1,pos2,len;
	while(cin>>s1>>s2){		
		len=s1.length();
		s1+=s1; s2+=s2;		
		cout<<CircularMatch(s1,s2,len,pos1,pos2)<<endl;
		cout<<pos1<<endl<<pos2<<endl;		
	}
	return 0;
}
