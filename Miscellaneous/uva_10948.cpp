#include <bits/stdc++.h>
#define ll long long
#define l long
#define ld long double
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define vecInt vector<int>

#define MAX 1000000

using namespace std;

bool prime[MAX+1];

void sieve()
{

    memset(prime, true, sizeof(prime));

    for(int j=2; j<=sqrt(MAX); j++)
    {
        if(prime[j])
        {
            for(int i=j*j; i<=MAX; i+=j)
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
    sieve();
    int n;
    bool flag = false;

    while( (cin >> n), n)
    {
        cout << n << ":" << endl;
        for(int p1=2; p1 <= n ; p1++) // p1 <= n/2 -- would reduce the time complexity from 0.290 to 0.150
        {
            int p2 = n - p1;

            if(prime[p2] && prime[p1])
            {

                cout << p1 << "+" << p2 << endl;
                flag=true;

                break;
            }


        }
        if(!flag)
            cout << "NO WAY!" << endl;

        flag = false;


    }

    return 0;
}
