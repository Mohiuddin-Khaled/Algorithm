// problem link: https://www.naukri.com/code360/problems/flloyd-warshall_2041979

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        d[u][v] = min(d[u][v], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < INF && d[k][j] < INF)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    return d[src][dest];
}
