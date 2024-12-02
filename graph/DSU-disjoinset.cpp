#include <bits/stdc++.h> // Include every standard library
using namespace std;
typedef long long ll;


class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findset_root(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findset_root(parent[node]);
    }

    void union_set(int u, int v) // by size
    {
        int root_u = findset_root(u);
        int root_v = findset_root(v);
        if (root_u != root_v) // not in same set
        {
            if (size[root_u] < size[root_v])
                swap(root_u, root_v);
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }

    bool same_set(int u, int v)
    {
        return findset_root(u) == findset_root(v);
    }
};


int main()
{
    DSU ds(7);
    ds.union_set(1, 2);
    ds.union_set(2, 3);
    ds.union_set(4, 5);
    ds.union_set(6, 7);
    ds.union_set(5, 6);
    // if 3 and 7 same or not
    if (ds.same_set(3, 7))
        cout << "Same\n";
    else
        cout << "Not same\n";

    ds.union_set(3, 7);

    if (ds.same_set(3, 7))
        cout << "Same\n";
    else
        cout << "Not same\n";
    return 0;
}