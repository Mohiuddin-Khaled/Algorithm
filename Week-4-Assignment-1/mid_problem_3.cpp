#include <bits/stdc++.h>
using namespace std;

const int N = 102;
vector<int> adj[N];
int parent[N];
bool visited[N];
int level[N];

void dfs(int src)
{
    visited[src] = true;
    for (int v : adj[src])
    {
        if (!visited[v])
        {
            parent[v] = src;
            level[v] = level[src] + 1;
            visited[v] = 1;
            dfs(v);
        }
    }
}

int main()
{
    int start = 2, end = 101;
    for (int u = start; u <= end; u++)
    {
        for (int v = u + 1; v <= end; v++)
        {
            if (v % u == 0)
            {
                adj[u].push_back(v);
            }
        }
    }
    // Initialize
    for (int i = start; i <= end; i++)
    {
        level[i] = 1;
        parent[i] = -1;
        visited[i] = false;
    }

    for (int i = start; i <= end; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    int value = start;
    for (int i = start; i <= end; i++)
    {
        if (level[i] > level[value])
            value = i;
    }
    vector<int> path;
    int curr = value;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";
    return 0;
}
