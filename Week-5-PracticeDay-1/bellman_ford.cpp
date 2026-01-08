#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
vector<vector<int>> edges;
vector<int> d(N, INT_MAX);
int n, m;

void bellmanFord(int src)
{
    d[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];

            if (d[u] != INT_MAX && (d[u] + w < d[v]))
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    bellmanFord(1);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INT_MAX)
        {
            cout << 30000 << " ";
        }
        else
        {
            cout << d[i] << " ";
        }
    }
    return 0;
}

// Bellman ford algorithm implementation use adjacency list
// Sparse Graph: O(n * m)
// Dense Graph: O(n * n)

// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> pii;
// const int N = 1e5 + 7;
// const int INF = 1e9;
// int d[N], n, m;
// vector<pii> g[N];

// void bellmanFord(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INF; // initialize all nodes distance to infinity
//     }
//     d[src] = 0;
//     for (int i = 1; i < n; i++) // iteration times: n - 1
//     {
//         for (int u = 1; u <= n; u++)
//         {
//             for (pii edge : g[u])
//             {
//                 int v = edge.first, w = edge.second;
//                 / relaxation
//                 if (d[u] != INF && d[u] + w < d[v])
//                 {
//                     d[v] = d[u] + w;
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     while (m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back(make_pair(v, w));
//     }
//     int src = 1;
//     bellmanFord(src);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << d[i] << " ";
//     }
//     return 0;
// }

// Bellman ford algorithm implementation use list of edges
// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;

// const int N = 1e5 + 5;
// const int INF = 1e9;
// vector<pair<pii, int>> edgeList;
// int n, m, d[N];

// void bellmanFord(int src)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INF;
//     }
//     d[src] = 0;
//     for (int i = 1; i < n; i++)
//     {
//         for (auto edge : edgeList)
//         {
//             int u = edge.first.first, v = edge.first.second, w = edge.second;
//             if (d[u] != INF && (d[v] > d[u] + w))
//             {
//                 d[v] = d[u] + w;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     while (m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edgeList.push_back({{u, v}, w});
//     }
//     int src = 1;
//     bellmanFord(src);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << d[i] << " ";
//     }
//     return 0;
// }
