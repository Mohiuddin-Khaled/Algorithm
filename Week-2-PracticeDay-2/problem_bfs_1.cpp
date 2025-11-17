/*
input:
    8 11
    1 2     3 4
    1 4     5 6
    2 3     5 7
    2 5     5 8
    2 7     7 8
    2 8
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
int visited[N];
int level[N];
int parent[N];
vector<pair<int, int>> edges;
bool has_cycle = false;

void bfs(int s)
{
    queue<int> q;
    level[s] = 0;
    visited[s] = 1;
    parent[s] = -1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == 0)
            {
                visited[v] = 1;
                parent[v] = u;
                level[v] = level[u] + 1;
                q.push(v);
            }
            else if (v != parent[u])
            {
                edges.push_back({u, v});
                has_cycle = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // u --> v
        // adj[v].push_back(u); // v --> u
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Level of Node " << i << ": " << level[i] << endl;
    }
    if (has_cycle)
    {
        cout << "Cycle Existed!" << endl
             << "Cross Edges:" << endl;
        for (pair<int, int> val : edges)
        {
            cout << "(" << val.first << "---" << val.second << "), ";
        }
    }
    else
    {
        cout << "No Cycle Existed!" << endl;
    }
    return 0;
}
