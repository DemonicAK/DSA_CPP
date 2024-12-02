
#include <bits/stdc++.h> // Include every standard library
using namespace std;
typedef long long ll;

class Solution
{

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = (1e9 + 7);
        int src = 0, des = n - 1;

        vector<pair<int, int>> adj[n]; // n nodes
        for (auto k : roads)
        {
            int from = k[0], to = k[1], edw = k[2];
            adj[from].push_back({to, edw});
            adj[to].push_back({from, edw});
        }

        // {cost,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        vector<long> dist(n, 1e18);
        dist[src] = 0;

        vector<int> ways(n, 0);
        ways[src] = 1;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ll cost = it.first;
            int node = it.second;
            for (auto it : adj[node])
            {
                int to = it.first, edw = it.second;

                if (edw + cost < dist[to])
                {
                    dist[to] = edw + cost;
                    pq.push({dist[to], to});
                    ways[to] = ways[node];
                }
                else if (edw + cost == dist[to])
                {
                    ways[to] = (ways[node] + ways[to]) % mod;
                }
            }
        }

        return ways[des] % mod;
    }
};

int main(){

cout<<1e4-1;
return 0;}