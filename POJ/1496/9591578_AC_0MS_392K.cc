#include<stdio.h>
#include<string.h>

char s[12];
long long int a[27][27];
int i,j;

int main()
{
    for(i=0;i<=26;i++)
        a[i][0]=1;
    for(i=1;i<=26;i++)
    for(j=1;j<=i;j++)
        a[i][j]=a[i-1][j]+a[i-1][j-1];
    while(scanf("%s",s)!=EOF)
    {
        long long int sum=1;
        int l=strlen(s),flag=0;

        for(i=1;i<l;i++)
        if(s[i]<=s[i-1])
        {
            printf("0\n");
            flag=1;
            break;
        }
        if(flag)continue;
        for(i=1;i<l;i++)
            sum+=a[26][i];
        for(i=l-1;i>0;i--)
        for(j=s[i-1]+1;j<s[i];j++)
            sum+=a[26-(j-'a'+1)][l-1-i];
        for(i=1;i<=s[0]-'a';i++)
            sum+=a[26-i][l-1];
        printf("%lld\n",sum);
    }

    return 0;
}
