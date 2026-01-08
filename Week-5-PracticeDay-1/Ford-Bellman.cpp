// problem link: https://eolymp.com/en/problems/1453
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<vector<int>> edges;
vector<int> d(N, INT_MAX);
int n, m;

void bellmanFord(int src)
{
    d[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];

            if (d[u] != INT_MAX && (d[u] + w < d[v]))
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    bellmanFord(1);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INT_MAX)
        {
            cout << 30000 << " ";
        }
        else
        {
            cout << d[i] << " ";
        }
    }
    return 0;
}