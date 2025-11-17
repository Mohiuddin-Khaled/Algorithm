// https://cses.fi/problemset/task/1679

/*
Constraints:
    1 <= n <= 10^5
    1 <= m <= 2 . 10^5
    1 <= a, b <= n

Input:
    5 3
    1 2
    3 1
    4 5

Output:
    3 4 1 5 2

- Assumption: Graph is Acyclic
- DAG: Directed Acyclic Graph
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N];
vector<int> result;

bool has_cycle = false;

void dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
            if (has_cycle)
                return;
        }
        else if (visited[adj_node] == 1)
        {
            has_cycle = true;
            return;
        }
    }
    visited[node] = 2;
    result.push_back(node);
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
        cout << "IMPOSSIBLE";
    }
    else
    {
        reverse(result.begin(), result.end());
        for (int val : result)
            cout << val << " ";
    }
    return 0;
}
