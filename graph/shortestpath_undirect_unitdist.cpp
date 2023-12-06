#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> makeadj(int V, vector<vector<int>> &edges, bool direction = 0)
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

public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        vector<vector<int>> adj = makeadj(N, edges);

        vector<int> dist(N + 1, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
// cout<<"here";
        while (!q.empty())
        {
        cout<<"here";
            int curr = q.front();
            q.pop();
            int newdist = dist[curr]+1;

            for (auto it : adj[curr])
            {
                dist[it] = min(newdist, dist[it]);
                q.push(it);
            }
        }

        return dist;
    }
};
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

int main(){
usaco();
    int n, m;
    bool direction = 0; // 0 for undirected graph and 1 for directed graph
    // cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // assuming vertices are 0 based indexed
        edges[i] = {u, v};
    }
    int src;
    cin >> src;
    Solution obj;
    vector<int> ans = obj.shortestPath(edges, n, m, src);
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;   
}