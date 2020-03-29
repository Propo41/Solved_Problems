#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
private:
    vector<vector<int>> adjList;
    vector <int> indegree;
    int nodes;

public:
    Graph(vector<Edge> edges, int n)
    {
        adjList.resize(n);
        nodes = n;
        vector<int> temp(n, 0);
        indegree = temp;

        for (auto edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            indegree[edge.dest]++;
        }

    }

    void kahn_topological_sort(vector<int> &sorted);
};


void Graph :: kahn_topological_sort(vector<int> &sorted)
{
    priority_queue<int, vector<int>, greater<int> > no_degree; // used a priority queue to allow choosing the node with lower priority.
    // special condition for the problem

    //linear search to find nodes having indegree value 0
    for(int i=0; i<this->nodes; i++)
        if(!indegree[i])
            no_degree.push(i);


    while(!no_degree.empty())
    {
        int u = no_degree.top();
        no_degree.pop();

        sorted.push_back(u);
        // for all adjacent nodes of u, remove an edge
        // and if it becomes 0, then push it into no_degree
        for(auto v: this->adjList[u])
        {
            indegree[v] -= 1;
            if(!indegree[v])
                no_degree.push(v);
        }

    }


}


int main()
{


    int n, nodes;
    string str1, str2;
    int tsc = 1;


    while(cin >> n)
    {

        map<string, int> bev;
        nodes = n;

        string names[n+1];

        for(int i=0; i<n; i++)
        {
            cin >> str1;
            bev.insert({str1, i});
            names[i]=str1;

        }

        cin >> n;
        vector<Edge> edges;
        for(int i=0; i<n; i++)
        {
            cin >> str1 >> str2;
            edges.push_back({bev[str1], bev[str2]});
        }

        vector<int> sorted;    // contains the topologically sorted nodes

        Graph graph(edges, nodes);

        // Perform Topological Sort
        graph.kahn_topological_sort(sorted);
        cout << endl;
        cout << "Case #" << tsc << ": Dilbert should drink beverages in this order: ";
        int l = sorted.size();
        for (int i=0; i<l; i++)
        {
            if(i!=l-1)
                cout << names[sorted[i]] << " ";
            else
                cout << names[sorted[i]] << ".";

        }

        cout << endl << endl;
        tsc++;
    }


    return 0;
}
