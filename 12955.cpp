#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)



using namespace std;

int main()
{
    FASTIO;

    long f[]={0,1,2,6,24,120,720,5040,40320};
      int c=0, r,n;
      int index;

    while(cin >> n)
    {
        c=0;
        for(int i=8; i>=0; i--)
        {
            if(f[i]<=n)
            {
                index = i;
                n=n-f[i];
                c+=1;
                break;
            }

        }

        while(n)
        {
            if(f[index]<=n)
            {
                r = n%f[index];
                int x = n/f[index];
                c+=x;
                n-=(f[index]*x);
            }
            else
                index--;

        }
        cout << c << endl;
    }



    return 0;
}
