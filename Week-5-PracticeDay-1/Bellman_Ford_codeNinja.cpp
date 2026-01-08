// problem link: https://www.codingninjas.com/studio/problems/bellmon-ford_2041977
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<int> d(n + 1, INF);
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
    return d;
}
