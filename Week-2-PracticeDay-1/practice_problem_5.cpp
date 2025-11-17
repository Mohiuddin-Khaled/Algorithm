#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int height[N];

void dfs(int node)
{
    visited[node] = true;
    for (auto adj_node : adj[node])
    {
        if (visited[adj_node])
        {
            continue;
        }
        dfs(adj_node);
        height[node] = max(height[adj_node] + 1, height[node]);
    }
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
    int heightNode;
    cin >> heightNode;
    cout << "height of " << heightNode << " = " << height[heightNode] << endl;
    return 0;
}