#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO;
    long long n;
    while(1)
    {
        cin >> n;
        if(n<0) break;

        if(n==1)
             cout << "0%" << endl;
        else
            cout << n*25 << "%" << endl;
    }

    return 0;
}
