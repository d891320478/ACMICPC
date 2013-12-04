#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
 int count;
 string str;
 while(getline(cin,str))
 {
  while( (count=str.find("you"))!=EOF )
   str.replace(count,3,"we");
  cout<<str<<'\n';
 }
 return 0;
}