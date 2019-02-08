#include <bits/stdc++.h>
#define ll long long
#define l long
#define ld long double
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define vecInt vector<int>
#define y 1000000
using namespace std;

bool prime[y+1];

void sieve()
{

    memset(prime, true, sizeof(prime));

    for(int j=2; j<=sqrt(y); j++)
    {
        if(prime[j])
        {
            for(int i=j*j; i<=y; i+=j)
            {
                prime[i]=false;
            }
        }
    }

}


int main()
{
    FASTIO;
    sieve();

    int n,p;

    while( cin >> n )
    {

        for(int i = n; ; i--)
        {
            if(prime[i]==true)
            {
                p = i;
                break;
            }

        }
        int leftIndex = 2;
        int rightIndex = p;

        while(true)
        {
            if(prime[leftIndex] == 0 )    
                leftIndex++;
            
            if(prime[rightIndex] == 0 )      
                rightIndex--;
    
            if(leftIndex + rightIndex < n)
            {
                leftIndex++;
                continue;
            }

            if(leftIndex + rightIndex > n)
            {
                rightIndex--;
                continue;

            }

            if(leftIndex + rightIndex == n)
            {
                cout << n << " = " << leftIndex << " + " << rightIndex << endl;
                break;
            }

        }
    }


    return 0;
}
