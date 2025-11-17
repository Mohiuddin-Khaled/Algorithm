#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int parent[N];
bool has_cycle = false;

void bfs(int node)
{
    queue<int> q;
    visited[node] = 1;
    parent[node] = -1;
    q.push(node);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == 0)
            {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
                if (has_cycle)
                    return;
            }
            else if (v != parent[u])
            {
                has_cycle = true;
            }
        }
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
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
            if (has_cycle)
                break;
        }
    }
    if (has_cycle)
        cout << "Cycle Detected!";
    else
        cout << "No Cycle Detected!";
    return 0;
}