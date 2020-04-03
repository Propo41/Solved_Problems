#include <bits/stdc++.h>

/*
PROBLEM LINK: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/pasha-jumps-on-a-permutation-june-easy-19-9e608b68/
The problem can be solved using a simple dijkstra's algo or 0-1 BFS.
0-1 BFS is used here

*/

using namespace std;

int bfs_modified(int adj[], map<int,int> index_tracker, int n)
{
    int u,v;
    deque <int> q;
    q.push_back(adj[1]);
    int cost[n+2];


    for(int i=1; i<=n; i++)
        cost[i]=INT_MAX;

    cost[0]=-1;
    cost[n+1]=-1;
    cost[adj[1]] = 0;

    while(!q.empty())
    {
        u = q.front();
        q.pop_front();

        int adj_node_index = index_tracker[u];

        v = adj[adj_node_index+1];
        if(cost[u]+1 < cost[v])
        {
            q.push_back(v);
            cost[v]=cost[u]+1;
        }

        v = adj[adj_node_index-1];
        if(cost[u]+1 < cost[v])
        {
            q.push_back(v);
            cost[v]=cost[u]+1;
        }

        v = adj[u];
        if(adj[u]!=u)
        {

            if(cost[u]+0 < cost[v])
            {
                cost[v]=cost[u]+0;
                q.push_front(v);

            }

        }

    }


    return cost[n];

}



int main()
{
    int tsc, n,a;

    cin >> tsc;

    while(tsc--)
    {
        cin >> n;
        int adj[n+2];
        map<int,int> index_tracker; // stores the indexes of the nodes as value

        adj[0]=0;
        adj[n+1]=0;
        for(int i=1; i<=n; i++)
        {
            cin >> a;
            adj[i]=a;
            index_tracker[a]=i;
        }

        cout << bfs_modified(adj, index_tracker, n) << endl;
    }






    return 0;
}
