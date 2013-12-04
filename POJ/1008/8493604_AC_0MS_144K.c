#include<stdio.h>
#include<string.h>

int n,i,j;
char s1[20],s2[20],s3[20],ch;
long int t1,t2,t3;
long int sum;
int day,year;

int haab(char m[])
{
    if(! strcmp(m,"pop"))return 0;        if(! strcmp(m,"no"))return 1;
    if(! strcmp(m,"zip"))return 2;      if(! strcmp(m,"zotz"))return 3;
    if(! strcmp(m,"tzec"))return 4;      if(! strcmp(m,"xul"))return 5;
    if(! strcmp(m,"yoxkin"))return 6;    if(! strcmp(m,"mol"))return 7;
    if(! strcmp(m,"chen"))return 8;      if(! strcmp(m,"yax"))return 9;
    if(! strcmp(m,"zac"))return 10;     if(! strcmp(m,"ceh"))return 11;
    if(! strcmp(m,"mac"))return 12;  if(! strcmp(m,"kankin"))return 13;
    if(! strcmp(m,"muan"))return 14;    if(! strcmp(m,"pax"))return 15;
    if(! strcmp(m,"koyab"))return 16; if(! strcmp(m,"cumhu"))return 17;
    if(! strcmp(m,"uayet"))return 18;
}

char *tzolkin(int d)
{
    switch (d)
    {
        case 1:return("imix");           case 2:return("ik");
        case 3:return("akbal");         case 4:return("kan");
        case 5:return("chicchan");     case 6:return("cimi");
        case 7:return("manik");       case 8:return("lamat");
        case 9:return("muluk");         case 10:return("ok");
        case 11:return("chuen");        case 12:return("eb");
        case 13:return("ben");          case 14:return("ix");
        case 15:return("mem");         case 16:return("cib");
        case 17:return("caban");     case 18:return("eznab");
        case 19:return("canac");       case 0:return("ahau");
    }
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s",s1,s2,s3);
        t1=0; t2=0; t3=0;

        for(j=0;s1[j+1];j++)
            t1=t1*10+s1[j]-'0';
        t2=haab(s2);
        for(j=0;s3[j];j++)
            t3=t3*10+s3[j]-'0';
        sum=t2*20+t1+1+t3*365;

        year=sum/260+((sum%260)?0:-1);
        day=sum%13;
        if(! day)day=13;
        printf("%d %s %d\n",day,tzolkin(sum%20),year);
    }

    return 0;
}
