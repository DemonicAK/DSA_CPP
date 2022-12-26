#include"bits/stdc++.h"
using namespace std;
 
 
 
 //it is to form a graph using matrix representation
 void addEdge(vector<vector<int>> &adj, int u, int v,int w=1)       //for weighted graph replace int by pair
 {
     adj[u][v]=w;
     adj[v][u]=w;
 }

 void initialize(vector<vector<int>> &adj, int V)
 {
     for(int i=0;i<V;i++)
     {
     adj.push_back(vector<int>(V,0));
     }
 }
 
 void printGraph(vector<vector<int>> &adj, int V)
 {
     for (int v = 0; v < V; ++v)
     {
         for (int u = 0; u < V; ++u)
             cout << adj[v][u] << " ";
         cout << endl;
     }
 }
 
 
 
 
 
int main()
{

    vector<vector<int>> adj;
    int V = 5;
    initialize(adj, V);


    addEdge(adj, 0, 1,2);
    addEdge(adj, 0, 4,3);
    addEdge(adj, 1, 2,3);
    addEdge(adj, 1, 3,4);
    addEdge(adj, 1, 4,4);



    printGraph(adj, V);




        return 0;
}