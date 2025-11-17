// https://cses.fi/problemset/task/1669
/*
bool detect_cycle(int node) {
    - mark visited[node] as 1

    - for all adj_node of adj_list[node]:

        Case-1: “node” is the parent of “adj_node”:
            - ignore

        Case-2: visited[adj_node] is 0:
            - mark "node" as the parent of "adj_node"
            / Same as directed graph

        Case-3: visited[adj_node] is 1:
            / Same as directed graph

        Case-4: visited[adj_node] is 2:
            / Same as directed graph

    - mark visited[node] as 2
    - return true
}
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
        if (adj_node == parent[node])
            continue;

        if (!visited[adj_node])
        {
            parent[adj_node] = node;
            dfs(adj_node);
            if (has_cycle)
                return;
        }
        else
        {
            has_cycle = true;
            start_node = adj_node;
            end_node = node;
            return;
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