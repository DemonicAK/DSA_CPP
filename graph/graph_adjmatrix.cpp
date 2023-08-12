#include <bits/stdc++.h>
using namespace std;



// it is to form a graph using adjacency matrix

// wieghted graph, directional and undirectional
class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int n)
    {
        numVertices = n;

        // Initialize the adjacency matrix with all zeros
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }


    void addEdge(int src, int dest, bool direction = 0,int weight1=1,int weight2=1)
    {
        // Function to add an edge

        // direction=0 means undirected graph
        // direction=1 means directed graph
        adjMatrix[src][dest] = weight1;
        if (!direction)
        {
            adjMatrix[dest][src] = weight2;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency matrix representation of the graph
    graph.printGraph();

    return 0;
}
