#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    int d[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            (i == j) ? d[i][j] = 0 : d[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    // floyd warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] != INF && d[k][j] != INF && (d[i][j] > d[i][k] + d[k][j]))
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][i] < 0)
            {
                cycle = true;
                break;
            }
            else
            {
                (d[i][j] == INF) ? cout << "INF" << " " : cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
    cycle ? cout << "cycle exists" : cout << "not cycle exists";
    return 0;
}