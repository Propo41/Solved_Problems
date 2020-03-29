#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define vecInt vector<int>
//#define SIZE 100000000
//#include "DontDeleteMeFunctions.h"

using namespace std;


//If a number is divisible by more than one prime number, then it obviously has a largest prime divisor.

ll primeFactor(ll n)
{

    int c=0;
    ll max=-1;
    bool flag = true;

    while(n%2==0)
    {
        max=2;
        c=1;
        n=n>>1;

    }
    for(int i = 3; i <= sqrt(n); i+=2)
    {
        while(n%i==0)
        {
            max=i;
            n/=i;
            if(flag)
            {
                c++;
                flag=false;
            }
        }
        flag=true;

    }

    if(n>2)
    {
        max=n;
        c++;

    }

    if(c>1)
        return max;
    else
        return -1;


}


int main()
{

    ll p;

    while( (cin >> p), p)
    {
        p=abs(p);
        ll ans = primeFactor(p);

        cout << ans << endl;

    }





    return 0;
}
