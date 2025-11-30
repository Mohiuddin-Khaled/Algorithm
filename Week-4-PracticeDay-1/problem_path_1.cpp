#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int parent[N];
int visited[N];
int level[N];

void dfs(int src)
{
    visited[src] = 1;
    for (int v : adj_list[src])
    {
        if (visited[v] == 0)
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v); // u ---> v
        adj_list[v].push_back(u); // v ---> u
    }
    int src_node, dst_node;
    cin >> src_node >> dst_node;
    dfs(src_node);
    vector<int> path;
    int curr = dst_node;
    while (true)
    {
        path.push_back(curr);
        if (curr == src_node)
            break;
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());
    cout << level[dst_node] << endl;
    for (int value : path)
    {
        cout << value << " ";
    }
    return 0;
}