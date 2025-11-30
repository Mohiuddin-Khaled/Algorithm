/*
- input --> A weighted graph and a source // O(n)
- output --> distance of all nodes from the source
- create a distance array 'd' // O(n)
- initialize all value of 'd' to infinity
- d[src] = 0
- create a visited array and mark all node as unvisited // O(n)
- for i = 0 to n - 1 // O(1) --> O(n)
    - pick the unvisited node with minimum distance value --> O(n^2)
    - visited[node] = 1 --> O(1)
    - for all adj_node of node: --> O(m)
        - if d[node] + c(node, adj_node) < d[adj_node]:
            - d[adj_node] = d[node] + c(node, adj_node)

- output array 'd'

    - Time Complexity: O(n^2)
    - Space Complexity -> O(n)

    7 8
    1 2 3
    1 3 5
    3 4 1
    4 6 1
    2 5 6
    5 6 1
    5 7 2
    3 7 12
*/

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
/// const long long int INF = 1e18;
// const int INF = 1e9;
// vector<pair<int, int>> adj_list[N];
// int d[N], visited[N];
// int n, m;

// void dijkstra(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INF;
//     }
//     d[src] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int selected_node = -1;
//         for (int j = 1; j <= n; j++)
//         {
//             if (visited[j] == 1)
//                 continue;
//             if (selected_node == -1 || d[selected_node] > d[j])
//             {
//                 selected_node = j;
//             }
//         }
//         visited[selected_node] = 1;
//         for (auto adj_entry : adj_list[selected_node])
//         {
//             int adj_node = adj_entry.first;
//             int edge_cost = adj_entry.second;
//             if (d[selected_node] + edge_cost < d[adj_node])
//             {
//                 d[adj_node] = d[selected_node] + edge_cost;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj_list[u].push_back({v, w});
//         adj_list[v].push_back({v, w});
//     }
//     int src = 1;
//     dijkstra(src);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << " " << d[i] << endl;
//     }
//     return 0;
// }

// Naive dijkstra - Queue - worst
// Time Complexity - O(n * m)
// 10^5 * 10^5 --> 10^10 (Time Limit Exceeded)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> g[N];
int d[N];

void dijkstra(int src)
{
    queue<int> q;
    d[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto adj_entry : g[u])
        {
            int v = adj_entry.first;
            int w = adj_entry.second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push(v);
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
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = INT_MAX;
    }
    int src = 1;
    dijkstra(src);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << d[i] << endl;
    }
    return 0;
}