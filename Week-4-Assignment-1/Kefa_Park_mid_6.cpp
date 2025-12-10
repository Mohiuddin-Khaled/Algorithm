#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> track(N);
vector<int> adj[N];
bool visited[N];
int n, m, cnt = 0;

void dfs(int node, int consecutive)
{
    visited[node] = true;
    if (track[node] == 1)
        consecutive++;
    else
        consecutive = 0;
    if (consecutive > m)
        return;
    bool leafNode = true;
    for (int adj_node : adj[node])
    {
        if (visited[adj_node])
            continue;
        leafNode = false;
        dfs(adj_node, consecutive);
    }
    if (leafNode)
        cnt++;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> track[i];

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << cnt;
    return 0;
}
