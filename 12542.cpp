#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define vecInt vector<int>
#define SIZE 100000
//#include "DontDeleteMeFunctions.h"

using namespace std;

bool prime[SIZE+1];

void sieve()
{

    memset(prime, true, sizeof(prime));

    for(int j=2; j<=sqrt(SIZE); j++)
    {
        if(prime[j])
        {

            for(int i=j*j; i<=SIZE; i+=j)
            {
                prime[i]=false;
            }
        }
    }
    prime[0]=0;
    prime[1]=0;
}

int main()
{

    FASTIO;
    sieve();
    string str;

    while((cin >> str))
    {
        int l = str.size();
        if(l==1 && str[0]=='0')
            break;
        ll max=-1;

        for(int i=0; i<l; i++)
        {
            ll p=0;
            for(int j=i; j<l; j++)
            {

                p=p*10 + (str[j]-'0');
                if(p > SIZE)
                    break;


                if(prime[p])
                {

                    if(p>max)
                        max=p;
                }

            }
        }
        cout << max << endl;

    }



    return 0;
}


