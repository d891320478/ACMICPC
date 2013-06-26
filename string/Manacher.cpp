char s[N],a[N<<1],ch;
int p[N<<1],la,ans;
void lpd()
{
	int mx=0,id;
	for(int i=1;i<la;i++)
	{
		if(mx>i) p[i]=min(p[id*2-i],mx-i);		else p[i]=1;
		for(;a[i+p[i]]==a[i-p[i]];p[i]++);
		if(p[i]+i>mx)	{	mx=p[i]+i;	id=i;		}
		ans=max(ans,p[i]-1);
	}
}
int main ()
{
	while (scanf("%s",s)!=-1)
	{
		scanf("%c",&ch);
		a[0]='$';		a[1]='#';		la=2;
		for(int i=0;s[i];i++)	{		a[la++]=s[i];		a[la++]='#';		}
		a[la++]=0;		ans=0;		lpd();
		printf("%d\n",ans);
	}
	return 0;
}
