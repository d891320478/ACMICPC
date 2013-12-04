#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char str[1010];
int main()
{
    int i;
    int len;
    while(cin.getline(str,1010))
    {
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(i+2<len&&str[i]=='y'&&str[i+1]=='o'&&str[i+2]=='u')
            {
                printf("we");
                i+=2;
                continue;
            }    
            printf("%c",str[i]);
        }    
        printf("\n");
    }    
    return 0;
}    