// https: // practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h> // Include every standard library
using namespace std;

class Solution
{
private:
    void dfs(int node, int vis[], stack<int> &st,
             vector<int> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }
        st.push(node);
    }

    public:
        // Function to return list containing vertices in Topological order.
        vector<int> topoSort(int V, vector<int> adj[])
        {
            vector<int> indegree(V, 0);
            for (int i = 0; i < V; i++)
            {
                for (auto j : adj[i])
                    indegree[j]++;
            }
            queue<int> q;
            for (int i = 0; i < V; i++)
            {
                if (!indegree[i])
                    q.push(i);
            }
            vector<int> topo;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                topo.push_back(node);

                for (auto nbr : adj[node])
                {
                    indegree[nbr]--;
                    if (!indegree[nbr])
                        q.push(nbr);
                }
            }
            return topo;
        }
        // Function to return list containing vertices in Topological order.
        vector<int> dfstopoSort(int V, vector<int> adj[])
        {
            int vis[V] = {0};
            stack<int> st;
            for (int i = 0; i < V; i++)
            {
                if (!vis[i])
                {
                    dfs(i, vis, st, adj);
                }
            }

            vector<int> ans;
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
    };

int main()
{
    int V=11;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(4);
    adj[4].push_back(7);
    adj[7].push_back(8);
    adj[8].push_back(3);
    adj[3].push_back(9);
    adj[9].push_back(10);

    Solution ob;
    vector<int> ans = ob.dfstopoSort(V, adj);
    // reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}