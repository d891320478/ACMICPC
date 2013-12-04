#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main ()
{
    while(cin>>n)
    {
        long cou,ma=0;
        long s[1010][2]={0};

        for (unsigned int i = 0; i < n; i += 1)
            cin>>s[i][0]>>s[i][1];
        if(n<=2)
        {
            cout<<n<<endl;
            continue;
        }
        for (unsigned int i = 0; i < n-1; i += 1)
        {
            double a[1010]={0};

            for (unsigned int j = i+1; j < n; j += 1)
                if(i!=j)
                {
                    if(s[i][0]-s[j][0]==0)a[j]=100000000000000.0;
                    else
                        a[j]=(s[j][1]-s[i][1])*1.000000/(s[j][0]-s[i][0]);
                }
            sort(a+i+1,a+n-1);
            cou=2;
            for (unsigned int j = i+2; j < n; j += 1)
            {
                if(a[j]==a[j-1])cou++;
                else cou=2;
                ma=ma>cou?ma:cou;
            }
        }
        cout<<ma<<endl;
    }

    return 0;
}
