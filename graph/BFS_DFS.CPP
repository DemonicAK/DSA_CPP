#include <bits/stdc++.h>
using namespace std;

// it is to form a graph using adjlistacency list

// Function to add an edge

class Graph
{
private:
    int V;

    vector<int>* adjlist;

public:
    Graph(int numVertices)

    {
         V = numVertices;
        // vector<int>* adjlist;

         adjlist = new vector<int>[V];
    }

    void addEdge(int src, int dest, bool direction = 0)
    {

        // direc = 1 refers to directional graph

        // direc = 0 refers to undirectional graph

        adjlist[src].push_back(dest);
        if (!direction)
        {
            adjlist[dest].push_back(src);
        }
    }

    void printGraph()
    {
        for (int v = 0; v < V; ++v)
        {
            // cout << "\n adjlistacency list of vertex "
            //      << v << "\n head ";
            cout << v << "->";
            for (auto x : adjlist[v])
                cout << x << "-> ";
            printf("\n");
        }
        cout << "\n";
    }
    ~Graph() // Destructor to deallocate memory
    {
        delete[] adjlist;
    }

    // bfs
    void bfs(int s) // s is for start   // and v is for vertices
    {
        bool visited[V]; // it is visited vector it is to keep record for visited nodes

        for (int i = 0; i < V; i++)
        {
            visited[i] = false; // initially all nodes are not visited
        }
        queue<int> q;      // queue for bfs
        q.push(s);         // push the start node in queue
        visited[s] = true; // mark the start node as visited
        while (!q.empty()) // while queue is not empty
        {
            int u = q.front();        // take the front element of queue
            q.pop();                  // pop the front element of queue
            cout << u << " ";         // print the front element of queue
            for (auto v : adjlist[u]) // for all the adjlistacent nodes of u
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
    void dfs(int s)
    {
        bool visited[V]; // it is visited vector it is to keep record for visited nodes

        for (int i = 0; i < V; i++)
            visited[i] = false; // initially all nodes are not visited

        stack<int> st;      // stack for dfs
        st.push(s);         // push the start node in stack
        visited[s] = true;  // mark the start node as visited
        while (!st.empty()) // while stack is not empty
        {
            int u = st.top();         // take the top element of stack
            st.pop();                 // pop the top element of stack
            cout << u << " ";         // print the top element of stack
            for (auto v : adjlist[u]) // for all the adjlistacent nodes of u
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
};

int main()
{

    Graph g(5);
    // int direction=0
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    cout << "Bfs traversal is : ";
    g.bfs(0);
    cout << "Dfs traversal is : ";
    g.dfs(0);

    return 0;
}
