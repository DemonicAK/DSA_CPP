
#include <bits/stdc++.h> // Include every standard library
using namespace std;

// https://www.codingninjas.com/studio/problems/detect-cycle-in-an-undirected-graph-_758967
void usaco(string filename = "")
{
    if (filename.size() > 0)
    {
#ifndef ONLINE_JUDGE
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
#endif
    }
    else
    {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
#endif
    }
}
class Graph
{
private:
    bool bfs(int src, vector<int> adj[], vector<bool> &vis)

    {

        queue<pair<int, int>> q;

        q.push({src, -1});

        vis[src] = true;

        while (!q.empty())

        {

            int node = q.front().first;

            int parent = q.front().second;

            q.pop();

            for (auto nbr : adj[node])

            {

                if (!vis[nbr])

                {

                    q.push({nbr, node});

                    vis[nbr] = true;
                }
                else if (vis[nbr] && nbr != parent)

                {

                    return true; // Cycle detected
                }
            }
        }

        return false; // No Cycle Detected
    }

public:
    bool detectCycle(int V, vector<int> adj[])
    {
        // Write your code here.
        // Write your code here.

        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)

        {

            if (!vis[i])

            {

                if (bfs(i, adj, vis))

                {

                    return true;
                }
            }
        }

        return false;
    }
    }
;

int main(){


    usaco();
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Graph obj;
        bool ans = obj.detectCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    
    return 0;
}