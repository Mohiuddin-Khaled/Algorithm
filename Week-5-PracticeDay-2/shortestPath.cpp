// problem link: https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj_list(n + 1);
    vector<ll> dist(n + 1, LLONG_MAX);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u])
            continue;

        for (auto adj : adj_list[u])
        {
            int v = adj.first;
            ll w = adj.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}