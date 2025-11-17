// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int visited[N];
int parent[N];
int start_node = -1, end_node = -1;
bool has_cycle = false;
vector<int> vec;

void bfs(int s)
{
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    vec.push_back(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (v == parent[u])
                continue;
            if (visited[v] == 0)
            {
                visited[v] = 1;
                parent[v] = u;
                vec.push_back(v);
                q.push(v);
                if (has_cycle)
                    return;
            }
            else
            {
                has_cycle = true;
                start_node = v;
                end_node = u;
                return;
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
        adj[v].push_back(u);
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
    {
        cout << vec.size() + 1 << endl;
        for (int value : vec)
            cout << value << " ";
        cout << vec[0];
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}