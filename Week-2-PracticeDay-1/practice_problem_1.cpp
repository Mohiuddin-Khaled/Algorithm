#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int node)
{
    visited[node] = true;
    for (int adj_node : adj[node])
    {
        if (!visited[adj_node])
        {
            dfs(adj_node);
        }
    }
    cout << node << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
}
