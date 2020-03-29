#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

ld quadraticSoln(ld a, ld b, ld c)
{
    ld D=b*b-4*a*c;
    return (-b+sqrt(D))/2*a;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ld n;
    int tsc;

    cin >> tsc;

    while(tsc--)
    {
        cin >> n;

        cout << (int) quadraticSoln(1,1,-2*n) << endl;
    }

    return 0;
}


