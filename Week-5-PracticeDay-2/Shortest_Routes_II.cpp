// problem link: https://cses.fi/problemset/task/1672/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const long long INF = 1e15;
long long d[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (d[u][v] >= INF)
            cout << -1 << endl;
        else
            cout << d[u][v] << endl;
    }
    return 0;
}
