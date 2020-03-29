#include <bits/stdc++.h>

using namespace std;

/*
PROBLEM: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
used modified bfs to keep track of the parent nodes while traversal.
then the parent node is uncovered starting from N to 1
*/

// returns the number of bridges crossed.
// uses modified bfs that tracks the parent vertex while traversing
int bfs ( vector < int > graph[], int curr, int V)
{

    queue < int > g_queue;
    g_queue.push(curr);
    bool visited[V+1] = {false};

    visited[curr]= true ;
    int parent[V+1] = {0};

    while (!g_queue.empty())
    {
        curr = g_queue.front();
        g_queue.pop();

        for(auto v: graph[curr])
        {
            if(!visited[v])
            {
                visited[v]=true;
                g_queue.push(v);
                parent[v] = curr; // track the parent vertex of v

            }

        }
    }
    int bridgesCrossed = 0;
    int u = V;
    while(parent[u])
    {
        u = parent[u];
        bridgesCrossed++;

    }

    return bridgesCrossed;
}

int main()
{


    int u,v;
    int V; // number of vertices
    int E; // number of edged
    int tsc;

    cin >> tsc;
    while(tsc--)
    {
        cin >> V >> E;
        vector < int > graph[V+1];

        for(int i=0; i<E; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cout << bfs(graph, 1, V) << endl;

    }


    return 0 ;

}
