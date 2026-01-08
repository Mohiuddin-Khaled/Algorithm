// Bellman ford algorithm implementation use list of edges

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<pii, int>> edgeList;
int n, m, d[N];

void bellmanFord(int src)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }

    d[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto edge : edgeList)
        {
            int u = edge.first.first, v = edge.first.second, w = edge.second;
            if (d[u] != INF && (d[v] > d[u] + w))
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({{u, v}, w});
    }
    int src = 1;
    bellmanFord(src);
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}