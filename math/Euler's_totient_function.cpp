//欧拉函数(<=n与n互素的个数)
/*
Phi(1)=1（小于等于1的正整数中唯一和1互质的数就是1本身）。
若n是质数p的k次幂，phi(n)=phi(p^k)=(p-1)*p^(k-1)，因为除了p的倍数外，其他数都跟n互质。
欧拉函数是积性函数，若mn互质则phi(mn)=phi(m)*phi(n)
(1) 若(N%a==0 && (N/a)%a==0) 则有:E(N)=E(N/a)*a;(2) 若(N%a==0 && (N/a)%a!=0) 则有:E(N)=E(N/a)*(a-1);  其中a是N的质因数。关于欧拉函数还有以下性质：(1) phi[p]=p-1;  (p为质数);(2)若N=p^n(p为质数)，则 phi[N]=(p-1)*p^(n-1);
*/
a[1]=1;
for(int i=2;i<=500000;i++)
{
　　if(! f[i]){ a[i]=i-1; prime[++prime[0]]=i; }
　　for(int j=1;j<=prime[0] && prime[j]*i<=500000;j++)
　　{		f[prime[j]*i]=1;
　　if(i%prime[j]==0)
　　{ a[i*prime[j]]=a[i]*prime[j]; break; }
　　else a[i*prime[j]]=a[i]*(prime[j]-1);
　　}
}
