#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define L 2147

using namespace std;

int main()
{
    FASTIO;
    int a,b,c,d,t;
    
    vector <int> sameNum(5001,0);

    for(int i=11; i<=5000; i++)
    {
        if(i>=11 && i <=99)
        {
            t=i;
            b=t%10;
            t/=10;
            a=t%10;

            if(a==b)
                sameNum[i-1]=1;

        }
       else if(i>=100 && i <=999)
        {
             t=i;
           c=t%10;
            t/=10;
            b=t%10;
            t/=10;
            a=t%10;

            if(a==b || b==c || a==c)
                sameNum[i-1]=1;

        }
        if(i>=1000 && i <=5000)
        {
             t=i;
            d=t%10;
            t/=10;
            c=t%10;
            t/=10;
            b=t%10;
            t/=10;
            a=t%10;

            if(a==b || b==c || a==c || a==d || b==d || c==d)
                sameNum[i-1]=1;

        }

    }

    while(cin >> a >> b)
    {
        int c = 0;

        for(int i=a; i<=b; i++)
        {
            if(sameNum[i-1]==1)
                c++;
        }
        cout << (b-a+1)-c << endl;

    }

    return 0;
}
