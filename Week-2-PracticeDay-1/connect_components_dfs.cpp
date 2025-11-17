// Number of connected components
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int connectComponents = 0;

void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
    {
        // cout << v << " ";
        if (visited[v])
            continue;
        dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        connectComponents++;
    }
    cout << "Number of Components: " << connectComponents << endl;
    return 0;
}