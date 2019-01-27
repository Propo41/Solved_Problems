#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO;
    int n;
    while((cin >> n), n)
    {
        if(n<=101)
            cout << "f91(" << n << ") = 91" << endl;
        else
            cout << "f91(" << n << ") = " << n-10 << endl;
    }


    return 0;
}
