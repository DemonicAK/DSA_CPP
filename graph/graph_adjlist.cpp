#include <bits/stdc++.h>
using namespace std;

template <typename T>

// it is to form a graph using adjacency list
class graph
{

public:
    unordered_map<T, vector<T>> adj; // declared the adjacency list

    void addEdge(T u, T v, bool direction) // for directed graph direction=1
    {
        // Function to add an edge

        // direction=0 means undirected graph
        // direction=1 means directed graph

        adj[u].push_back(v);

        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {

        for (auto i : adj)
        {

            cout << i.first << "-> ";
            for (auto x : i.second)
            {
                cout << x << ", ";
            }

            cout << "\n";
        }
        cout << "\n";
    }
};

vector<vector<int>> makeadj(int V, vector<vector<int>> edges, bool direction = 0)
{
    vector<vector<int>> adj(V);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        if (!direction)
            adj[edge[1]].push_back(edge[0]); // undirected graph
    }
    return adj;
}

int main()
{
    int n, m;
    bool direction = 0; // 0 for undirected graph and 1 for directed graph

    cout << "Enter the number of nodes : " << endl;

    cin >> n;

    cout << "Enter the number of edges : " << endl;

    cin >> m;

    graph<int> g;

    cout << "Enter the edges : " << endl;

    for (int i = 0; i < m; i++)

    {

        int u, v;

        cin >> u >> v;
        g.addEdge(u, v, direction);
    }

    g.printGraph();

    return 0;
}
