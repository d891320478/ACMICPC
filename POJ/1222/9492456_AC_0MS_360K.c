#include<stdio.h>

int press[10][10],puzzle[10][10];

void se()
{
 int i,j;
 for(i=1;i<=6;i++)
  press[1][i]=0;
 while(1)
 {
  for(i=2;i<=5;i++)
  {
   for(j=1;j<=6;j++)
   {
    press[i][j]=(puzzle[i-1][j]+press[i-1][j]+press[i-1][j+1]+press[i-1][j-1]+press[i-2][j])%2;
   }
  }
  for(i=1;i<=6;i++)
  {
   if((puzzle[5][i]+press[5][i-1]+press[5][i+1]+press[4][i]+press[5][i])%2!=0)
    break;
  }
  if(i>6) break;
  press[1][1]++;
  i=1;
  while(press[1][i]>1)
  {
   press[1][i]-=2;
   i++;
   press[1][i]++;
  }
 }
}

int main()
{
 int t,tc,i,j;
 scanf("%d",&t);
 for(tc=1;tc<=t;tc++)
 {
  for(i=1;i<=5;i++)
  {
   for(j=1;j<=6;j++)
    scanf("%d",&puzzle[i][j]);
  }
  for(i=0;i<=7;i++)
   press[0][i]=0,press[6][i]=0;
  for(i=0;i<=6;i++)
   press[i][0]=0,press[i][7]=0;
  se();
  printf("PUZZLE #%d\n",tc);
  for(i=1;i<=5;i++)
  {
   for(j=1;j<=6;j++)
   {
    printf("%d ",press[i][j]);
   }
   printf("\n");
  }
 }
 return 0;
}