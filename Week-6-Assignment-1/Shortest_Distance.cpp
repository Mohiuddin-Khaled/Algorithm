#include <bits/stdc++.h>
using namespace std;
const int N = 101;
long long dis[N][N];
const long long INF = 1e18;

void floydWarshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dis[i][j] = 0;
            }
            else
            {
                dis[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b], w);
    }

    floydWarshall(n);

    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (dis[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }

    return 0;
}
