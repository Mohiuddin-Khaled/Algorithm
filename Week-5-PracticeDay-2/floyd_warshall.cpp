// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e3 + 5;
// const int INF = 1e9;
// int d[N][N];

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             d[i][j] = INF;
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         d[u][v] = w;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         d[i][i] = 0;
//     }
//     for (int k = 1; k <= n; k++)
//     {
//         for (int u = 1; u <= n; u++)
//         {
//             for (int v = 1; v <= n; v++)
//             {
//                 d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << d[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


// floyd warshall algorithm
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int main()
{
    int n, e;
    cin >> n >> e;
    int dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            (i == j) ? dis[i][j] = 0 : dis[i][j] = INF;
        }
    }
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            (dis[i][j] == INF) ? cout << "INF" << " " : cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    // floyd warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF && (dis[i][k] + dis[k][j] < dis[i][j]))
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    cout << "Updated distance" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            (dis[i][j] == INF) ? cout << "INF" << " " : cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}