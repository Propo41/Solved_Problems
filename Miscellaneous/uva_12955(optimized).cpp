#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)



using namespace std;

int main()
{
    FASTIO;

    int f[]={0,1,2,6,24,120,720,5040,40320};
    int c=0,n;

    while(cin >> n)
    {
        c=0;
        for(int i=8; i>=1; i--)
        {
            if(n/f[i]> 0)
            {
                int x = n/f[i];
                c+=x;
                n-=(f[i]*x);
            }

        }

        cout << c << endl;
    }

    return 0;
}
