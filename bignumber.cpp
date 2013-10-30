struct bignumber
{
	int n;
	int a[MM];
	void clear()
	{ n=0; memset(a,0,sizeof(a)); }
	void init(char *s)
	{
		clear(); n=strlen(s);
		for(int i=0;s[i];++i) a[n-i]=s[i]-'0';
		while (a[n]==0 && n>1) --n;
	}
	void init(int s)
	{
		clear();
		if(s==0) { n=1; return; }
		while (s) { a[++n]=s%10; s/=10; }
	}
	void output()
	{ for(int i=n;i>0;i--) printf("%d",a[i]); printf("\n"); }
	int operator < (bignumber b)
	{
		if(n<b.n) return 1; if(n>b.n) return 0;
		for(int i=n;i>0;i--)
		{ if(a[i]<b.a[i]) return 1; if(a[i]>b.a[i]) return 0; }
		return 0;
	}
	int operator == (bignumber b)
	{
		if(n!=b.n) return 0;
		for(int i=n;i>0;i--) if(a[i]!=b.a[i]) return 0;
		return 1;
	}
	int operator <= (bignumber b)//>返回0，<返回2，=返回1
	{
		if(n<b.n) return 2;
		if(n>b.n) return 0;
		for(int i=n;i>0;--i)
		{
			if(a[i]>b.a[i]) return 0;
			if(a[i]<b.a[i]) return 2;
		}
		return 1;
	}
};
bignumber operator + (bignumber a,bignumber b)
{
	a.n=max(a.n,b.n);
	for(int i=1;i<=a.n;i++)
	{
		a.a[i]+=b.a[i];
		a.a[i+1]+=a.a[i]/10;
		a.a[i]%=10;
	}
	if(a.a[a.n+1]>0) a.n++;
	return a;
}
bignumber operator - (bignumber a,bignumber b)
{
	for(int i=1;i<=a.n;i++)
	{
		a.a[i]-=b.a[i];
		if(a.a[i]<0) { a.a[i+1]--; a.a[i]+=10; }
	}
	while (a.a[a.n]==0 && a.n>1) a.n--;
	return a;
}
bignumber operator * (bignumber a,int b)
{
	for(int i=1;i<=a.n;i++)
	{ a.a[i]=a.a[i]*b+a.a[i-1]/10; a.a[i-1]%=10; }
	while (a.a[a.n]>=10)
	{ a.n++; a.a[a.n]=a.a[a.n-1]/10; a.a[a.n-1]%=10; }
	return a;
}
bignumber operator * (bignumber a,bignumber b)
{
	bignumber c;
	c.clear();
	c.n=a.n+b.n;
	for(int i=1;i<=a.n;++i)
	for(int j=1;j<=b.n;++j)
		c.a[i+j-1]+=a.a[i]*b.a[j];
	for(int i=1;i<=c.n;++i)
	{
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	while(c.n>1 && c.a[c.n]==0) --c.n;
	return c;
}
bignumber operator / (bignumber a,int b)
{
	int tmp=0;
	for(int i=a.n;i>0;i--)
	{ tmp=tmp*10+a.a[i]; a.a[i]=tmp/b; tmp%=b; }
	while (a.a[a.n]==0 && a.n>1) a.n--;
	return a;
}
bignumber operator / (bignumber a,bignumber b)
{
	bignumber c,d;
	d.init(0);
	int i,j;
	for(i=a.n;i>=1;--i)
	{
		if(! (d.n==1 && d.a[1]==0))
		{
			for(j=d.n;j>0;--j) d.a[j+1]=d.a[j];
			++d.n;
		}
		d.a[1]=a.a[i];
		c.a[i]=0;
		while(b<=d)
		{
			d=d-b;
			++c.a[i];
		}
	}
	c.n=a.n;
	while(c.n>1 && c.a[c.n]==0) --c.n;
	return c;
}
bignumber gcd(bignumber a,bignumber b)
{
	int ans=0;
	bignumber c;
	while (1)
	{
		if(a.n==1 && a.a[1]==0) { c=b; break; }
		if(b.n==1 && b.a[1]==0) { c=a; break; }
		int flag=0;
		if(a.a[1]%2==0) a=a/2,flag++;
		if(b.a[1]%2==0) b=b/2,flag++;
		if(flag==2) ans++;
		if(! flag)
		if(a<b) b=b-a;
		else a=a-b;
	}
	while (ans--) c=c*2;
	return c;
}
