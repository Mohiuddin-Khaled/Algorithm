#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
int visited[N];
int parent[N];
bool has_cycle = false;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adjList[u])
        {
            if (visited[v] == 0)
            {
                parent[v] = u;
                visited[v] = 1;
                q.push(v);
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
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            bfs(i);
    }
    if (has_cycle)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
