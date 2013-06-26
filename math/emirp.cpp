//反素数：g(x)表示 x含有因子的数目，设 0<i<=x  则g(i)<=x;
//性质一:一个反素数的质因子必然是从2开始连续的质数.
//性质二:p=2^t1*3^t2*5^t3*7^t4.....必然t1>=t2>=t3>=....
int ss[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
long long ans,sum,n;
void dfs(int _i,long long now,long long _ss,int limit)
{
	if(_i>16) return;
	if(now>n) return;
	if(_ss>sum || _ss==sum && ans>now)
	{
		ans=now;
		sum=_ss;
	}
	long long p=ss[_i];
	for(int i=1;i<=limit;++i,p*=ss[_i])
	{
		if(now*p>n) break;
		dfs(_i+1,now*p,_ss*(i+1),i);
	}
}
int main ()
{
	while (cin>>n)
	{
		ans=sum=1;
		dfs(0,1,1,50);
		cout<<ans<<endl;
	}
	return 0;
}
