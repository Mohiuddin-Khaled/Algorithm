// https://cses.fi/problemset/task/1667/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    level[src] = 1;
    visited[src] = 1;
    parent[src] = -1;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                parent[adj_node] = head;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src_node = 1;
    bfs(src_node);
    int dst_node = n;
    if (visited[dst_node] == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << level[dst_node] << endl;
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
    for (int value : path)
        cout << value << " ";
    return 0;
}