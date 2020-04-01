#include <bits/stdc++.h>

using namespace std;


/*
PROBLEM LINK: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/agitated-chandan/
we need to find the maximum distance from a leaf node to another leaf node
*/


pair<int,int> bfs(int start, vector<pair<int,int>> graph[], int n)
{
    queue < int > g_queue;
    g_queue.push(start);
    bool visited[n+1]= {false};
    visited[start]= true;
    int depth[n+1] = {0}; // stores the depth of node i, where i is the index, from the start node
    // so, the diameter of a tree would be the maximum element in this array

    while (!g_queue.empty())
    {
        start = g_queue.front();
        g_queue.pop();

        // for every unvisited vertex v adjacent to node start
        // push it into the queue
        for(auto v: graph[start])
        {
            if(!visited[v.first])
            {
                visited[v.first]=true;
                g_queue.push(v.first);
                depth[v.first] = depth[start] + v.second; // since, the edges have weights, we are adding it.
            }

        }
    }


    int max = INT_MIN;
    int leaf_node;
    for(int i=1; i<=n; i++)
    {
        if(depth[i]>max)
        {
            max = depth[i];
            leaf_node = i;
        }

    }

    //cout << *max_element(depth+1, depth+n+1) << endl;

    pair <int,int> leaf(leaf_node, max);
    return leaf;

}





int main()
{

    int tsc, n, u,v,w;
    cin >> tsc;

    while(tsc--)
    {
        cin >> n;
        vector<pair<int,int>> graph[n+1];
        //vector<vector<int> > edgeWeight( n+1, vector<int> (n+1, 0));
        int cost = 0;

        // taking input
        for(int i=1; i<n; i++)
        {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
            //edgeWeight[u][v] = w;
            //edgeWeight[v][u] = w;
        }

        int start_leaf = bfs(1, graph, n).first; // start traversal from node 1. Any node would do. Returns a pair object containing leaf node and it's diameter
        int max_dist = bfs(start_leaf, graph, n).second; // now traverse the graph from one leaf node to another.


        if(max_dist<=100)
            cost = 0;
        else if(max_dist > 10000)
            cost = 10000;
        else if(max_dist > 1000)
            cost = 1000;
        else
            cost = 100;


        cout << cost << " " << max_dist << endl;


    }


    return 0;
}
