// problem link: https://eolymp.com/en/problems/1455

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> w(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    vector<ll> dist(n, 0);
    vector<int> parent(n, -1);
    int last_updated_node = -1;
    for (int i = 0; i < n; i++)
    {
        last_updated_node = -1;
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (w[u][v] == 100000)
                    continue;

                if (dist[v] > dist[u] + w[u][v])
                {
                    dist[v] = dist[u] + w[u][v];
                    parent[v] = u;
                    last_updated_node = v;
                }
            }
        }
    }
    if (last_updated_node == -1)
    {
        cout << "NO";
        return 0;
    }
    int x = last_updated_node;
    for (int i = 0; i < n; i++)
        x = parent[x];
    vector<int> cycle;
    int cur = x;
    do
    {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (x != cur);
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << endl;
    cout << cycle.size() << endl;
    for (int value : cycle)
    {
        cout << value + 1 << " ";
    }
    return 0;
}