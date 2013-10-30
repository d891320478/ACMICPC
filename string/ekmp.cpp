void getnext(char *s)
{
	int ls=strlen(s),j=0,k=1;
	while (j<ls && s[j]==s[j+1]) ++j;
	next[0]=ls;
	next[1]=j;
	for(int i=2;i<ls;++i)
	{
		int len=k+next[k]-1,l=next[i-k];
		if(l<len-i+1) next[i]=l;
		else
		{
			j=max(0,len-i+1);
			while(i+j<ls && s[i+j]==s[j]) ++j;
			next[i]=j;
			k=i;
		}
	}
}
int match(char *s1,char *s2)
{
	int ans=0,j=0,k=0,la=strlen(s1),lb=strlen(s2);
	while(j<la && j<lb && s1[j]==s2[j]) ++j;
	ekmp[0]=j;
	if(j==lb) ++ans;
	for(int i=1;i<la;++i)
	{
		int len=k+ekmp[k]-1,l=next[i-k];
		if(l<len-i+1) ekmp[i]=l;
		else
		{
			j=max(0,len-i+1);
			while(i+j<la && j<lb && s1[i+j]==s2[j]) ++j;
			ekmp[i]=j;
			k=i;
		}
		if(ekmp[i]==lb) ++ans;
	}
	return ans;
}
