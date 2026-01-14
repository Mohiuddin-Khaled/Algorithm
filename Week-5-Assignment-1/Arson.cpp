// problem link: https://eolymp.com/en/problems/4369

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int d[N];
queue<int> q;

int main()
{
    int n, m;
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;
    cin >> k;
    while (k--)
    {
        int src;
        cin >> src;
        if (d[src] == -1)
        {
            d[src] = 0;
            q.push(src);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (d[v] != -1)
                continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    int mn = 1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > d[mn])
            mn = i;
    }
    cout << d[mn] << endl
         << mn;
    return 0;
}
