#include <bits/stdc++.h>

using namespace std;

int main()
{


    int v,u, c = 0;
    cin >> v;

    while(v--)
    {
        cin >> u;
        if(u==1)
            c++;
    }

    if(c>=2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0 ;

}

