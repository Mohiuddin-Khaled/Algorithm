/*
Linear Connected Graph:
    1 – 2 – 3 – 4 – 5 – 6

This is a connected graph of six nodes arranged in a linear path.
Every node (except the first and last) is connected to exactly two other nodes.
If we start breadth first search(BFS) from node 1, it first visits node 2, then 3,
then continues along the single available path to 4, 5, and finally 6.
Because there are no branches or alternate connections,
BFS proceeds sequentially through all the nodes in order.
The BFS traversal output is therefore 1, 2, 3, 4, 5, 6,
which is the same as the order of nodes along the path.

BFS Traversal Input:
    6 5
    1 2
    2 3
    3 4
    4 5
    5 6

DFS Traversal Output:
    1 → 2 → 3 → 4 → 5 → 6
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int head = q.front();
        cout << head << " ";
        q.pop();
        for (int adjNode : adj[head])
        {
            if (visited[adjNode])
            {
                continue;
            }
            q.push(adjNode);
            visited[adjNode] = true;
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
        adj[v].push_back(u);
    }
    bfs(1);
    return 0;
}