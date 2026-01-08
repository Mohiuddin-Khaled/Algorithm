// problem link: https://cses.fi/problemset/task/1673

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, long long int> pii;

const int N = 1e5 + 5;
vector<pii> adj[N];
long long d[N];
int n, m;
bool negative_cycle = false;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, -w});
    }
    for (int i = 1; i <= n; i++)
        d[i] = LLONG_MAX;

    d[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (pii adj_node : adj[node])
            {
                int u = node, v = adj_node.first;
                long long w = adj_node.second;
                if (d[u] != LLONG_MAX && d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    if (i == n)
                        negative_cycle = true;
                }
            }
        }
    }
    if (negative_cycle)
    {
        cout << -1;
    }
    else
    {
        cout << -d[n];
    }
    return 0;
}