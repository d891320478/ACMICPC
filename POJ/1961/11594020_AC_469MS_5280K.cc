#include <cstdio>
#include <cstring>
#define N 1000010
int p[N],n;
char s[N];
int main ()
{
	int tt=0;
	while(scanf("%d",&n) && n)
	{
		if(tt) printf("\n");
		printf("Test case #%d\n",++tt);
		scanf("%s",s);
		p[0]=-1;
		for(int i=1,j=-1;i<n;i++)
		{
			while (j>-1 && s[j+1]!=s[i]) j=p[j];
			if(s[j+1]==s[i]) j++;
			p[i]=j;
			//printf("%d\n",j);
			if(j!=-1)
			if((i+1)%(i-j)==0) if((i+1)/(i-j)>1) printf("%d %d\n",i+1,(i+1)/(i-j));
		}
	}
	return 0;
}