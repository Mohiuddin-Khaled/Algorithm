#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];

void dfs(int node)
{
    visited[node] = true;
    for (auto adj_node : adj[node])
    {
        if (visited[adj_node])
        {
            continue;
        }
        depth[adj_node] = depth[node] + 1;
        dfs(adj_node);
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
    int depthNode;
    cin >> depthNode;
    cout << "Depth of " << depthNode << " = " << depth[depthNode] << endl;
    return 0;
}