// problem link: https://eolymp.com/en/problems/978

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101];

void dfs(int src)
{
    visited[src] = true;
    for (int v : adj[src])
    {
        if (visited[v] == true)
            continue;
        visited[v] = false;
        cout << src << " " << v << endl;
        dfs(v);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int startNode = 1, endNode = n;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    return 0;
}