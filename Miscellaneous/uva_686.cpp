#include <bits/stdc++.h>
#define ll long long
#define l long
#define ld long double
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define vecInt vector<int>

#define MAX 32769

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
    FASTIO;
    sieve();
    int n;

    while( (cin >> n), n)
    {
        int c = 0;
        int checkRepeat[MAX]={0};

        for(int p1=2; p1 <= n ; p1++)
        {
            int p2 = n - p1;
            if(p1==p2)
                checkRepeat[p1]++;
            else
            {
                checkRepeat[p1]++;
                checkRepeat[p2]++;
            }

            if(prime[p2] && prime[p1] && checkRepeat[p1]==1 && checkRepeat[p2]==1)
                c++;
            
        }
        
        cout << c << endl;

    }

    return 0;
}
