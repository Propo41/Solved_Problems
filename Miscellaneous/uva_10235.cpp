#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define vecInt vector<int>
#define SIZE 1000000
using namespace std;

bool prime[SIZE];

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
    prime[1]=1;
}
// An Emirp (Prime spelt backwards) is a Prime that gives you a ***different*** Prime when its digits are reversed.

bool emirp(int n)
{
    int temp = n;

    int rev=0, r;
    while(n>0)
    {
        r = n%10;
        rev = (rev*10) + r;
        n/=10;

    }

    if(rev == temp)
        return false;

    if(prime[rev])
        return true;

    return false;
}


int main()
{
    sieve();

    int n;

    while(cin >> n)
    {

        if(!prime[n])
            cout << n << " is not prime." << endl;
        else if(prime[n] && !emirp(n))
            cout << n << " is prime." << endl;
        else
            cout << n << " is emirp." << endl;

    }





    return 0;
}
