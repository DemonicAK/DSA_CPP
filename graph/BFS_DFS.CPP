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
            cout << x << "-> ";
        printf("\n");
    }
    cout << "\n";
}

// bfs
void bfs(vector<int> adj[], int s, int V) // s is for start   // and v is for vertices
{
    bool visited[V]; // it is visited vector it is to keep record for visited nodes

    for (int i = 0; i < V; i++)
        visited[i] = false; // initially all nodes are not visited

    queue<int> q;      // queue for bfs
    q.push(s);         // push the start node in queue
    visited[s] = true; // mark the start node as visited
    while (!q.empty()) // while queue is not empty
    {
        int u = q.front();    // take the front element of queue
        q.pop();              // pop the front element of queue
        cout << u << " ";     // print the front element of queue
        for (auto v : adj[u]) // for all the adjacent nodes of u
        {
            if (!visited[v]) // if the node is not visited
            {
                q.push(v);         // push the node in queue
                visited[v] = true; // mark the node as visited
            }
        }
    }

    cout << "\n";
}

// dfs
void dfs(vector<int> adj[], int s, int V)
{
    bool visited[V]; // it is visited vector it is to keep record for visited nodes

    for (int i = 0; i < V; i++)
        visited[i] = false; // initially all nodes are not visited

    stack<int> st;      // stack for dfs
    st.push(s);         // push the start node in stack
    visited[s] = true;  // mark the start node as visited
    while (!st.empty()) // while stack is not empty
    {
        int u = st.top();     // take the top element of stack
        st.pop();             // pop the top element of stack
        cout << u << " ";     // print the top element of stack
        for (auto v : adj[u]) // for all the adjacent nodes of u
        {
            if (!visited[v]) // if the node is not visited
            {
                st.push(v);        // push the node in stack
                visited[v] = true; // mark the node as visited
            }
        }
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

    cout << "Bfs traversal is : ";
    bfs(adj, 0, V);
    cout << "Dfs traversal is : ";
    dfs(adj, 0, V);

    return 0;
}


