// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;

// const int N = 1e5 + 5;
// vector<pii> adj[N];
// int d[N], n, m;
// bool negative_cycle = false;

// void bellman_ford(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INT_MAX;
//     }
//     d[src] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int node = 1; node <= n; node++)
//         {
//             for (pii adj_node : adj[node])
//             {
//                 int u = node;
//                 int v = adj_node.first;
//                 int w = adj_node.second;
//                 if (d[u] + w < d[v])
//                 {
//                     d[v] = d[u] + w;
//                     if (i == n)
//                         negative_cycle = true;
//                 }
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
//         adj[u].push_back(make_pair(v, w));
//     }
//     int src = 1;
//     bellman_ford(src);
//     if (negative_cycle)
//     {
//         cout << "Graph has negative cycle!" << endl;
//     }
//     else
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             cout << d[i] << " ";
//         }
//     }
//     return 0;
// }
