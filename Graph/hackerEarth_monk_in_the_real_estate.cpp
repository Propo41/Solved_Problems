#include <bits/stdc++.h>

using namespace std;

/*
PROBLEM: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-in-the-real-estate/
we just need to find the number of unique cities visited which can be done using a set
*/

int main()
{

    int tsc, e, u, v;

    cin >> tsc;

    while(tsc--)
    {
        set <int> cities;
        cin >> e;
        for(int i=0; i<e; i++)
        {
            cin >> u >> v;
            cities.insert(u);
            cities.insert(v);

        }
        cout << cities.size() << endl;
    }
    return 0;
}
