// Single Source Shortest Path (SSSP) in a DAG using DFS

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<int, int>> adj[N];
bool visited[N];
int shortPath[N];
vector<int> topSort;

void dfs(int u)
{
    visited[u] = true;
    for (pair<int, int> edge : adj[u])
    {
        int v = edge.first;
        if (!visited[v])
            dfs(v);
    }
    topSort.push_back(u);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src;
    cin >> src;

    for (int i = 1; i <= n; i++)
        shortPath[i] = INF;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    shortPath[src] = 0;

    for (int u : topSort)
    {
        if (shortPath[u] != INF)
        {
            for (pair<int, int> edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                shortPath[v] = min(shortPath[v], shortPath[u] + w);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (shortPath[i] < INF)
        {
            cout << "Shortest Path " << i << ": " << shortPath[i] << endl;
        }
        else
        {
            cout << "Shortest Path " << i << ": " << "INF" << endl;
        }
    }
    return 0;
}