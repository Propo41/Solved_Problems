#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pie acos(-1)

//this problem has the same solution as in gcd(a,b)=gcd(b,a%b); all you have to do is store the values of the remainder and quotient in an array;

using namespace std;

int main()
{
    int n,d,r,i=1,h;
    vector <int> vec;

    while(cin >> n >> d)
    {
        while(1)
        {
            h=n/d;
            vec.push_back(h);
            r=n%d;
            n=d,d=r;
            if(n==1)break;
            i++;
        }

        for(int i=0; i<vec.size(); i++)
        {
            if(i==0)
                cout << "[" << vec[i] << ";";
            else if(i==vec.size()-1)
                cout << vec[i] <<"]" << endl;
            else
                cout << vec[i] << ",";
        }
        vec.clear();


    }

    return 0;

}



