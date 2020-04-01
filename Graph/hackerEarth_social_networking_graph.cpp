#include <bits/stdc++.h>

/*

PROBLEM: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
The question is basically asking us to find the number of nodes in the nth level of the graph.
*/
using namespace std;


int bfs_modified( vector<int> graph[], int src, int t, int V)
{

    int level[V] = {0};
    queue < int > g_queue;
    g_queue.push(src);
    bool visited[V]={false};
    visited[src]= true;

    level[src] = 0; // meaning, the src node is at level 0
    while (!g_queue.empty())
    {
        src = g_queue.front();
        g_queue.pop();

        // for every unvisited vertex v adjacent to node curr
        // push it into the queue
        for(auto v: graph[src])
        {
            if(!visited[v])
            {
                visited[v]=true;
                g_queue.push(v);
                level[v]=level[src] + 1; // the child node's level = parent node's level + 1

            }

        }

    }

    int sum = 0;
    for(int i=0; i<V; i++)
        if(level[i]==t)
            sum+=1;

    return sum;


}




int main()
{
    int V,E;
    int u,v;

    cin >> V >> E;

    vector<int> graph[V];

    for(int i=0; i<E; i++)
    {
        cin >> u >> v ;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    int m, src,t;

    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> src >> t;

        if(t == 1)
            cout << graph[src].size() << endl;
        else
            cout << bfs_modified(graph, src, t, V) << endl;

    }


    return 0;
}



