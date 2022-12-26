#include <bits/stdc++.h>
using namespace std;

// it is to form a graph using adjacency list

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v) // for directed graph replace int by pair
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        // cout << "\n Adjacency list of vertex "
        //      << v << "\n head ";
        cout << v << "->";
        for (auto x : adj[v])
            cout << x <<"-> ";
        printf("\n");
    }
    cout << "\n";
}



int main()
{

    int V = 5;
    vector<int> adj[V]; // it is array of vectors

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, V);



    return 0;
}

// int arr[]; // it is array of (integers)
// vector<int> arr; // it is array of (vector of integers)
