#include <cstdio>
char s[1000002];
long long sum;
struct point
{
	long long x,y;
}a,b;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%s",s);
		sum=0;
		a=(point){0,0};
		for(int i=0;s[i+1];i++)
		{
			if(s[i]=='1')b=(point){a.x-1,a.y-1};
			if(s[i]=='2')b=(point){a.x,a.y-1};
			if(s[i]=='3')b=(point){a.x+1,a.y-1};
			if(s[i]=='4')b=(point){a.x-1,a.y};
			if(s[i]=='6')b=(point){a.x+1,a.y};
			if(s[i]=='7')b=(point){a.x-1,a.y+1};
			if(s[i]=='8')b=(point){a.x,a.y+1};
			if(s[i]=='9')b=(point){a.x+1,a.y+1};
			sum+=a.x*b.y-a.y*b.x;
			a=b;
		}
		if(sum<0)sum=-sum;
		printf("%lld",sum/2);
		if(sum%2)printf(".5");
		printf("\n");
	}
	
	return 0;
}
