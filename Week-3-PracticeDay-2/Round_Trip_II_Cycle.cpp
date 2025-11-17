// https://cses.fi/problemset/task/1678

/*
Constraints:
    1 <= n <= 10^5
    1 <= m <= 2 * 10^5
    1 <= a, b <= n

Input:
    4 5
    1 3
    2 1
    2 4
    3 2
    3 4

Output:
    4
    2 1 3 2

- visited[adj_node] == 0 --> unexplored node apply dfs()
- visited[adj_node] == 1 --> "paused" node cycle detected
- visited[adj_node] == 2 --> "done" node continue
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N];
int parent[N];
int start_node = -1, end_node = -1;

bool has_cycle = false;

void dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            parent[adj_node] = node;
            dfs(adj_node);
            if (has_cycle)
            {
                return;
            }
        }
        else if (visited[adj_node] == 1)
        {
            has_cycle = true;
            start_node = adj_node;
            end_node = node;
            return;
        }
    }
    visited[node] = 2;
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
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            if (has_cycle)
                break;
        }
    }
    if (has_cycle)
    {
        vector<int> cycle_node;
        cycle_node.push_back(start_node);
        while (end_node != start_node)
        {
            cycle_node.push_back(end_node);
            end_node = parent[end_node];
        }
        cycle_node.push_back(start_node);
        reverse(cycle_node.begin(), cycle_node.end());
        cout << cycle_node.size() << endl;
        for (int val : cycle_node)
        {
            cout << val << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}