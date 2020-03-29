#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define FASTIO  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;

bool checkNum(int n)
{
    int r;
    if(n%7==0)
        return true;
    while(n>0)
    {
        r=n%10;
        if(r==7)
            return true;
        n/=10;
    }
    return false;
}


int main()
{
    FASTIO;

    int n, k, m;

    while(( cin >> n >> m >> k), (n || m || k))
    {
        int i=1, c=1,clap=1;
        bool bound=false;

        while(1)
        {

            if(i==m)
            {

                if(checkNum(c))
                {
                    if(clap==k)
                    {
                        cout << c << endl;
                        break;
                    }

                    clap++;

                }

            }

            if(i==n)
            {
                bound=true;
                i=n-1;
            }
            else if(i==1)
            {
                bound=false;
                i=2;
            }
            else if(bound)
                i--;

            else if(!bound)
                i++;

            c++;

        }
    }


    return 0;
}
