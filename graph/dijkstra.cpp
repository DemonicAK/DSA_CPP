

#include <bits/stdc++.h> // Include every standard library
using namespace std;

typedef long long ll;

vector<int> dijkstra_pq(int V, vector<vector<int>> adj[], int Src)
{
    // Code here
    // priority_queue
    vector<int> dist(V, 1e9);
    dist[Src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, Src});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto x : adj[node])
        {
            int adj_node = x[0];
            int wt = x[1];

            if (dist[adj_node] > dis + wt)
            {
                dist[adj_node] = dis + wt;
                pq.push({dist[adj_node], adj_node});
            }
        }
    }
    return dist;
}

vector<int> dijkstra_set(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    // set
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    dist[S] = 0;

    st.insert({0, S});

    while (!st.empty())
    {
        auto it = *(st.begin());

        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto x : adj[node])
        {
            int adj_node = x[0];
            int wt = x[1];

            if (dis + wt < dist[adj_node])
            {
                // erase if exists
                if (dist[adj_node] == 1e9)
                    st.erase({dist[adj_node], adj_node});
                dist[adj_node] = dis + wt;
                st.insert({dist[adj_node], adj_node});
            }
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist = dijkstra_pq(V, adj, 0);
    for (auto x : dist)
        cout << x << " ";
    cout << endl;

    dist = dijkstra_set(V, adj, 0);
    for (auto x : dist)
        cout << x << " ";
    cout << endl;


return 0;
}