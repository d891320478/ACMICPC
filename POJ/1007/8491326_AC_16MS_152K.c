#include<stdio.h>

struct
{
   char s[51];
   int l;
}a[101],temp;
int n,m,i,j,k;

int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%s",a[i].s);
        for(j=0;a[i].s[j];j++)
        for(k=j+1;a[i].s[k];k++)
            if(a[i].s[k]<a[i].s[j])a[i].l++;
    }
    for(i=0;i<m-1;i++)
    for(j=m-1;j>i;j--)
        if(a[j].l<a[j-1].l)
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    for(i=0;i<m;i++)
        printf("%s\n",a[i].s);

    return 0;
}
