/*
DFS Traversal Steps
    Start at 4, visit → {4}
    Go to 1 → {4, 1}
    From 1, go to 2 → {4, 1, 2}
    From 2, go to 5 → {4, 1, 2, 5}
    From 5, go to 6 → {4, 1, 2, 5, 6}
    Backtrack to 5, go to 8 → {4, 1, 2, 5, 6, 8}
    Backtrack to 2, go to 7 → {4, 1, 2, 5, 6, 8, 7}
    Backtrack fully to 4, visit 3 → {4, 1, 2, 5, 6, 8, 7, 3}
    Backtrack again, visit 9 → {4, 1, 2, 5, 6, 8, 7, 3, 9}

DFS Traversal Input:
    9 8
    4 1
    4 3
    4 9
    1 2
    2 5
    2 7
    5 6
    5 8

DFS Traversal Output:
    4 → 1 → 2 → 5 → 6 → 8 → 7 → 3 → 9
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int node)
{
    cout << node << " ";
    visited[node] = true;
    for (auto adj_node : adj[node])
    {
        if (visited[adj_node])
            continue;
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
    dfs(4);
    return 0;
}