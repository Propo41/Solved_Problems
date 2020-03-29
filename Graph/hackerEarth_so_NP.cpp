# include <bits/stdc++.h>

using namespace std ;

/*
PROBLEM: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/so-np-c559f406/

NOTE: the number of independent cycles for undirected graph is just: edges minus vertices plus connected components
If we remove one edge from every cycle (if exist) then the connected components is unchanged.
After doing that, we just need to check how many more components we need to make to reach our desired value of k.
We do this by: m-n + comp + (k-comp)
therefore, we can see that the simplifying the equation we'll get m-n+k. This is the answer.
We don't need to call bfs to check number of components of the graph.

*/


void bfs ( vector < int > graph[], int curr, bool visited[])
{

    queue < int > g_queue;
    g_queue.push(curr);
    visited[curr]= true ;

    while (!g_queue.empty())
    {
        curr = g_queue.front();
        g_queue.pop();

        // for every unvisited vertex v adjacent to node curr
        // push it into the queue
        for(auto v: graph[curr])
        {
            if(!visited[v])
            {
                visited[v]=true;
                g_queue.push(v);
            }

        }
    }
}
int main ()
{
    int n,m,k;
    int u,v;

    cin >> n >> m >> k;
    vector < int > graph[n+1];
    int indeg[n+1]= {0};

    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        indeg[u]+=1;
        indeg[v]+=1;

    }

    int comp = 0;
    bool visited[n+1]= {false};

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            bfs(graph, i, visited);
            comp++;
        }
    }

    if (comp > k)
        cout << -1 << endl;

    else
        cout << m-n+comp + (k-comp)  << endl;





    return 0 ;
}


