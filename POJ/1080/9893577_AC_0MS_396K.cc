#include <cstdio>
#include <cstring>

int t;
int a[5][5]={{5,-1,-2,-1,-3},
			 {-1,5,-3,-2,-4},
			 {-2,-3,5,-2,-2},
			 {-1,-2,-2,5,-1},
			 {-3,-4,-2,-1,0}
			};

int z(char ch)
{
	if(ch=='A')return 0;
	if(ch=='C')return 1;
	if(ch=='G')return 2;
	if(ch=='T')return 3;
}

int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		char s[110],t[110];
		int ls,lt,l[110][110]={0};

		scanf("%d %s%d %s",&ls,s,&lt,t);
		for(int i=1;i<=ls;i++)
		{
			int k=z(s[i-1]);
			l[i][0]=l[i-1][0]+a[k][4];
		}
		for(int i=1;i<=lt;i++)
		{
			int k=z(t[i-1]);
			l[0][i]=l[0][i-1]+a[4][k];
		}
		for(int i=1;i<=ls;i++)
		for(int j=1;j<=lt;j++)
		{
			int maxx=-99999,k=z(s[i-1]),m=z(t[j-1]);

			maxx=maxx>l[i-1][j-1]+a[k][m]?maxx:l[i-1][j-1]+a[k][m];
			maxx=maxx>l[i-1][j]+a[k][4]?maxx:l[i-1][j]+a[k][4];
			maxx=maxx>l[i][j-1]+a[4][m]?maxx:l[i][j-1]+a[4][m];
			l[i][j]=maxx;
		}
		printf("%d\n",l[ls][lt]);
	}
	
	return 0;
}